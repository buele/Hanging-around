//
//  exceptions.h
//  TaskManager
//


#ifndef TaskManager_exceptions_h
#define TaskManager_exceptions_h

// TODO: manage exceptions as classes

// DBManager exceptions
struct MYSQLConnectionException{
    const char * what() const noexcept { return "MYSQL server connection fails"; };
};
struct MYSQLInvalidTimeException{
    const char * what() const noexcept { return "MYSQL Invalid time"; };
};
struct MYSQLValidQueryException{
    const char * what() const noexcept { return "MYSQL query not valid"; };
};
struct StmtInitializationException{
    const char * what() const noexcept { return "Could not initialize stmt"; };
};
struct PrepareStatementException{
    const char * what() const noexcept { return "Could not prepare statement"; };
};
struct BindParametersException{
    const char * what() const noexcept { return "Could not bind parameters"; };
};
struct ExecuteStatementException{
    const char * what() const noexcept { return "Could not execute statement"; };
};
struct TooLongNewTaskNameException{
    const char * what() const noexcept { return "Task name too long"; };
};
struct InvalidIdException{
    const char * what() const noexcept { return "Invalid id"; };
};

#endif
