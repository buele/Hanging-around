//
//  DBManager.cpp
//  TaskManager
//


#include <mysql.h>
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include "structures.h"
#include "exceptions.h"
#include "DBManager.h"

using namespace std;

bool DBManager::createTaskTable(){
    return true;
}

bool DBManager::createTask(string name){
    if(name.length() > MAX_NAME_CHAR) throw tooLongNameEx;
    
    MYSQL_STMT * stmt;
    MYSQL_BIND param[1];
    
    stmt = mysql_stmt_init(connection);
    if(!stmt) throw stmtInitEx;
    if (mysql_stmt_prepare(stmt, createTaskSQL.c_str(), createTaskSQL.length()) != 0) throw prepareStmtEx;
    
    memset (param, 0, sizeof (param));
    param[0].buffer_type    = MYSQL_TYPE_STRING;
    param[0].buffer         = (void *) name.c_str();
    param[0].buffer_length  = name.length();
    param[0].is_unsigned    = 0;
    param[0].is_null        = 0;
    param[0].length         = 0;
    
    if (mysql_stmt_bind_param(stmt, param) != 0) throw  bindParamsEx;
    if (mysql_stmt_execute(stmt) != 0) throw executeStmtEx;

    return true;
}

bool DBManager::completeTask(int taskId){
    if(taskId < 0) throw invalidIdEx;
    
    MYSQL_STMT * stmt;
    MYSQL_BIND param[1];
    
    stmt = mysql_stmt_init(connection);
    if(!stmt) throw stmtInitEx;
    if (mysql_stmt_prepare(stmt, completedTaskSQL.c_str(), completedTaskSQL.length()) != 0) throw prepareStmtEx;
    
    memset (param, 0, sizeof (param));
    param[0].buffer_type    = MYSQL_TYPE_LONG;
    param[0].buffer         = (void *) &taskId;
    param[0].buffer_length  = sizeof(int);
    param[0].is_unsigned    = 0;
    param[0].is_null        = 0;
    param[0].length         = 0;
    
    if (mysql_stmt_bind_param(stmt, param) != 0) throw  bindParamsEx;
    if (mysql_stmt_execute(stmt) != 0) throw executeStmtEx;
    
    return true;
}

bool DBManager::archiveTask(int taskId){
    if(taskId < 0) throw invalidIdEx;
    
    MYSQL_STMT * stmt;
    MYSQL_BIND param[1];
    
    stmt = mysql_stmt_init(connection);
    if(!stmt) throw stmtInitEx;
    if (mysql_stmt_prepare(stmt, archiveTaskSQL.c_str(), archiveTaskSQL.length()) != 0) throw prepareStmtEx;
    
    memset (param, 0, sizeof (param));
    param[0].buffer_type    = MYSQL_TYPE_LONG;
    param[0].buffer         = (void *) &taskId;
    param[0].buffer_length  = sizeof(int);
    param[0].is_unsigned    = 0;
    param[0].is_null        = 0;
    param[0].length         = 0;
    
    if (mysql_stmt_bind_param(stmt, param) != 0) throw  bindParamsEx;
    if (mysql_stmt_execute(stmt) != 0) throw executeStmtEx;
    
    return true;
}

vector<struct PendingTaskRow>  DBManager::tasksList(){
    const int idIndex= 0;
    const int nameIndex = 1;
    vector<PendingTaskRow> tasks;
    int esit = mysql_real_query (& mysql, this->tasksListSQL.c_str(), (unsigned int) this->tasksListSQL.length());
    if(esit){ /*TODO: manage error */}
    MYSQL_RES * res = mysql_store_result (& mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row (res))){
        PendingTaskRow result;
        result.id = row[idIndex]?row[idIndex]:"";
        result.name = row[nameIndex]?row[nameIndex]:"";
        tasks.push_back(result);
    }
    mysql_free_result (res);
    
    return tasks;
}


time_t DBManager::stringToTime_t(string time){
    
    if(&time){
        struct tm stm;
        strptime(time.c_str(), "%F %X", &stm);
        return (&stm)?mktime(&stm):NULL;
    }else
        return -1;
}

long int DBManager::diffTimeByStartAndEndString( string start, string end){
    if(!start.length() || !end.length()) return -1;
    return (long int) difftime(stringToTime_t(end),stringToTime_t(start));
}

TMDate DBManager::diffTMDateByStartAndEndString(string start, string end){
    const int secondsPerDay = 86400;
    const int secondsPerHour = 3600;
    const int secondsPerMinutes = 60;
    const int hoursPerDay = 24;
    TMDate date;
    date.days =0;
    date.hours = 0;
    date.minutes =0;
    if(!start.length() || !end.length()) return date;
    long int  diffSeconds = diffTimeByStartAndEndString(start, end);
    if(diffSeconds >= 0){
        date.days = (int)(diffSeconds / secondsPerDay);
        date.hours = (diffSeconds / secondsPerHour) % hoursPerDay ;
        date.minutes = (diffSeconds / secondsPerMinutes) % secondsPerMinutes;
    }
    
    return date;
}

vector<CompletedTaskRow> DBManager::completedTaskList(){
    const int idIndex           = 0;
    const int nameIndex         = 1;
    const int startTimeIndex    = 2;
    const int endTimeIndex      = 3;
    vector<CompletedTaskRow> tasks;
    int esit = mysql_real_query (& mysql, this->completedTasksListSQL.c_str(), (unsigned int) this->completedTasksListSQL.length());
    if(esit) throw queryNotValidEx;
    MYSQL_RES * res = mysql_store_result (& mysql);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row (res))){
        if(!(row[startTimeIndex]) || !(row[endTimeIndex])) throw invalidTimeEx;
        CompletedTaskRow taskItem;
        TMDate diffDate = diffTMDateByStartAndEndString(row[startTimeIndex]? row[startTimeIndex]: "", row[endTimeIndex]? row[endTimeIndex]: "");
        taskItem.id = row[idIndex]?row[idIndex]:"";
        taskItem.name = row[nameIndex]?row[nameIndex]:"";
        taskItem.days = to_string(diffDate.days);
        taskItem.hours = to_string(diffDate.hours);
        taskItem.minutes = to_string(diffDate.minutes);
        tasks.push_back(taskItem);
    }
    mysql_free_result (res);
    
    return tasks;
}

DBManager::DBManager(){
    mysql_init(&(this->mysql));
    this->connection = mysql_real_connect(&(this->mysql),
                                          this->host,
                                          this->user,
                                          this->password,
                                          this->db,
                                          this->port,
                                          this->unix_socket,
                                          this->client_flag);
    if (!connection) throw this->failedMYSQLConnectionEx;
}

DBManager::~DBManager(){
    mysql_close(this->connection);
}