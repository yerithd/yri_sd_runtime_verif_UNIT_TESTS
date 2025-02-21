/*
 * _YRI_RTM_IMPLEMENTATION_FILE_NAME
 *
 */

#include "_YRI_RTM_HEADER_FILE_NAME"


#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>


#include "utils/yr-db-runtime-verif-logger.hpp"

#include "yri_sd_runtime_verif/YRI_CPP_MONITOR.hpp"
#include "yri_sd_runtime_verif/YRI_CPP_MONITOR_STATE.hpp"
#include "yri_sd_runtime_verif/YRI_CPP_MONITOR_EDGE.hpp"


void _YRI_RTM_REPLACEMENT_QSTRING::YRI_CALL_BACK_final_state(YRI_CPP_MONITOR 			*a_runtime_monitor,
																													 YRI_CPP_MONITOR_EDGE 	*an_EDGE_leading_TO_error_FINAL_state)
{
    if (0 != a_runtime_monitor)
    {
        ( (YRI_DB_RUNTIME_VERIF_Monitor *) a_runtime_monitor)
        		->YRI_DB_RUNTIME_VERIF_Monitor_notify_SUCCESS_VERIFICATION(an_EDGE_leading_TO_error_FINAL_state);
    }
}



_YRI_RTM_REPLACEMENT_QSTRING::_YRI_RTM_REPLACEMENT_QSTRING()
    :YRI_DB_RUNTIME_VERIF_Monitor()
{
    __event_edge_DEFINITIONSYRRTMREPLACEMENTQSTRING__
}


_YRI_RTM_REPLACEMENT_QSTRING::_YRI_RTM_REPLACEMENT_QSTRING(YRI_DB_RUNTIME_VERIF_Logger *logger)
    :YRI_DB_RUNTIME_VERIF_Monitor(logger)
{
    __event_edge_DEFINITIONSYRRTMREPLACEMENTQSTRING__
}


/**
 * THIS METHOD PERFORMS EFFECTIVE TEMPORAL LINEAR
 * LOGIC CHECK AFTER A STATE EVENT (or system event)
 * could be achieved by the runtime monitor system !
 *
 * A SERIOUS VERIFICATION CLIENT MUST OVERRIDE THIS
 * METHOD !
 */
bool _YRI_RTM_REPLACEMENT_QSTRING::DO_VERIFY_AND_or_CHECK_ltl_PROPERTY(
    QString sql_table_ADDED_with_file_AND_line_number,
    uint	sql_record_qty_MODIFIED,
    YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER cur_SQL_command
    /* = YRI_CPP_UTILS::SQL_CONSTANT_IDENTIFIER::UNDEFINED_SQL_COMMAND */)
{
    QStringList sql_table_ADDED_with_file_AND_line_number_LIST =
        sql_table_ADDED_with_file_AND_line_number.split(";", Qt::KeepEmptyParts);

    QString sql_table_name = sql_table_ADDED_with_file_AND_line_number_LIST.at(0);

    QString CPP_FILE_NAME = sql_table_ADDED_with_file_AND_line_number_LIST.at(1);

    QString cpp_line_number = sql_table_ADDED_with_file_AND_line_number_LIST.at(2);


    qDebug() << "\t "
             << QString("[C++_STMT (%1.%2)[%3,%4] at %5:%6]").
             arg(YRI_CPP_UTILS::_DB_STMT_verification_ToUserViewString.
                 value(cur_SQL_command), sql_table_name,
                 QString::number(cur_SQL_command),
                 QString::number(sql_record_qty_MODIFIED), CPP_FILE_NAME,
                 cpp_line_number);


    switch(cur_SQL_command)
    {
    case YRI_CPP_UTILS::INSERT:
        break;

    case YRI_CPP_UTILS::SELECT:
        break;

    case YRI_CPP_UTILS::UPDATE:
        break;

    case YRI_CPP_UTILS::DELETE:
        break;

    default:

        break;
    }

    return false;
}


__slots_event_DEFINITIONS_YRI_RTM_REPLACEMENT_QSTRING__

