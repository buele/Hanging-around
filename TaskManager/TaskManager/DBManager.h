//
//  DBManager.h
//  TaskManager
//



#ifndef __TaskManager__DBManager__
#define __TaskManager__DBManager__


using namespace std;

struct TMDate{
    int days;
    int hours;
    int minutes;
};


class DBManager{
private:
    // queries
    const string createTasksTablesSQL = "CREATE TABLE `test`.`tasks` ( "
                                        "`id` INT NOT NULL AUTO_INCREMENT, "
                                        "`name` VARCHAR(255) NOT NULL, "
                                        "`start_time` DATETIME NOT NULL, "
                                        "`end_time` DATETIME NULL, "
                                        "`completed` BIT NULL DEFAULT 0, "
                                        "`archived` BIT NULL DEFAULT 0, "
                                        "PRIMARY KEY (`id`)); ";
    
    const string createTaskSQL =        "INSERT INTO tasks "
                                        "( name, start_time) "
                                        "VALUES "
                                        "( ? ,NOW());";
    
    const string completedTaskSQL =     "UPDATE tasks "
                                        "SET  end_time = NOW(), completed = 1 "
                                        "WHERE id = ?";
    
    const string archiveTaskSQL =       "UPDATE tasks "
                                        "SET   archived = 1 "
                                        "WHERE id = ?; ";
    
    const string tasksListSQL =         "SELECT id, name "
                                        "FROM tasks "
                                        "WHERE completed = 0 AND archived = 0; ";
    
    const string completedTasksListSQL= "SELECT id, name, start_time, end_time "
                                        "FROM tasks "
                                        "WHERE completed = 1 AND archived = 0; ";
    
    // constants
    const char * host = "localhost";
    const char * user = "root";
    const char * password = "";
    const char * db = "test";
    const unsigned int port = 0;
    const char * unix_socket = NULL;
    const unsigned long client_flag = 0;
    const short int MAX_NAME_CHAR = 255;
    
    // attributes
    MYSQL * connection;
    MYSQL  mysql;
    MYSQLConnectionException failedMYSQLConnectionEx;
    
    // exceptions
    StmtInitializationException stmtInitEx;
    PrepareStatementException prepareStmtEx;
    BindParametersException bindParamsEx;
    ExecuteStatementException executeStmtEx;
    TooLongNewTaskNameException tooLongNameEx;
    InvalidIdException invalidIdEx;
    MYSQLValidQueryException queryNotValidEx;
    MYSQLInvalidTimeException invalidTimeEx;
    
    // methods
    time_t stringToTime_t(string time);
    long int diffTimeByStartAndEndString(string start, string end);
    TMDate diffTMDateByStartAndEndString(string start, string end);
    
public:
    DBManager();
    ~DBManager();
    bool createTaskTable();
    
    bool createTask(string name);
    bool completeTask(int taskId);
    bool archiveTask(int taskId);
    vector<struct CompletedTaskRow> completedTaskList();
    vector<struct PendingTaskRow> tasksList();
};

#endif /* defined(__TaskManager__DBManager__) */
