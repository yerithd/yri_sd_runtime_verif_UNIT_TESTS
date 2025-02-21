/*
 * YRI_UTILS_GENERATOR_MONITOR_TEST.cpp
 *
 *      Author: Pr. Prof. Dr.-Ing. XAVIER Noumbissi NOUNDOU
 */

#include "YRI_UTILS_GENERATOR_MONITOR_TEST.hpp"

#include "../yri_sd_runtime_verif/src/YRI_CPP_MONITOR_STATE.hpp"

QString YRI_UTILS_GENERATOR_MONITOR_TEST::C_STATE = "C";

QString YRI_UTILS_GENERATOR_MONITOR_TEST::D_STATE = "D";

QString YRI_UTILS_GENERATOR_MONITOR_TEST::E_STATE = "E";

QString YRI_UTILS_GENERATOR_MONITOR_TEST::C_D_state_transition_EVENT_TOKEN = "'delete'";

QString YRI_UTILS_GENERATOR_MONITOR_TEST::D_E_state_transition_EVENT_TOKEN = "'yeroth'";


YRI_CPP_MONITOR_STATE *YRI_UTILS_GENERATOR_MONITOR_TEST::_a_root_STATE = 0;

YRI_CPP_MONITOR_EDGE *YRI_UTILS_GENERATOR_MONITOR_TEST::_an_edge_TEST = 0;


YRI_CPP_MONITOR *YRI_UTILS_GENERATOR_MONITOR_TEST::_A_RUNTIME_MONITOR_FOR_TESTING = 0;


void YRI_UTILS_GENERATOR_MONITOR_TEST::initTestCase()
{
	QVERIFY (0 != _A_RUNTIME_MONITOR_FOR_TESTING);
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::cleanupTestCase()
{
}


YRI_UTILS_GENERATOR_MONITOR_TEST::~YRI_UTILS_GENERATOR_MONITOR_TEST()
{
	if (0 != _A_RUNTIME_MONITOR_FOR_TESTING)
	{
		delete _A_RUNTIME_MONITOR_FOR_TESTING;

		_A_RUNTIME_MONITOR_FOR_TESTING = 0;
	}
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_TEST()
{
	//qDebug() << "START YR MONITOR TEST";

	QString YRI_RUNTIME_3 = "YRI_RUNTIME_3";

	_A_RUNTIME_MONITOR_FOR_TESTING = YRI_CPP_MONITOR::CREATE_MONITOR(YRI_RUNTIME_3);

	QVERIFY (0 != _A_RUNTIME_MONITOR_FOR_TESTING);

	QString ERROR_MESSAGE_WHEN_TEST_FAILS =
			QString("%1 VS. %2")
				.arg(YRI_RUNTIME_3,
					 _A_RUNTIME_MONITOR_FOR_TESTING->get_RUNTIME_MONITOR_NAME());

	bool RUNTIME_MONITOR_NAME_FINE =
			YRI_CPP_UTILS::isEqualsCaseInsensitive(YRI_RUNTIME_3,
					_A_RUNTIME_MONITOR_FOR_TESTING->get_RUNTIME_MONITOR_NAME());

	QVERIFY2 (RUNTIME_MONITOR_NAME_FINE, ERROR_MESSAGE_WHEN_TEST_FAILS.toStdString().c_str());
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_EDGE_TEST()
{
	//qDebug() << "RUNTIME MONITOR INSTANTIATED";

	_an_edge_TEST = 0;

	_an_edge_TEST = _A_RUNTIME_MONITOR_FOR_TESTING->create_yri_monitor_edge(D_STATE, E_STATE);

	QVERIFY (0 != _an_edge_TEST);

	YRI_CPP_MONITOR_EVENT *an_event = _an_edge_TEST->set_EDGE_EVENT(D_E_state_transition_EVENT_TOKEN);

	QVERIFY (0 != an_event);

	_a_root_STATE = _an_edge_TEST->get_SOURCE_STATE();

	QVERIFY (0 != _a_root_STATE);

	_a_root_STATE->set_START_STATE(*_A_RUNTIME_MONITOR_FOR_TESTING, true);

	if (_an_edge_TEST->get_TARGET_STATE())
	{
		_an_edge_TEST->get_TARGET_STATE()->set_FINAL_STATE(true);
	}

	YRI_CPP_MONITOR_EDGE * a_root_edge =
			_A_RUNTIME_MONITOR_FOR_TESTING
						->create_yri_monitor_edge(YRI_CPP_UTILS::EMPTY_STRING,
												 _a_root_STATE->get_MONITOR_STATE_NAME());

	QVERIFY2 (0 != a_root_edge, "a_root_edge = 0");

	_A_RUNTIME_MONITOR_FOR_TESTING->set_yri_root_edge(a_root_edge);

	QVERIFY2 (0 != _A_RUNTIME_MONITOR_FOR_TESTING->get_current_triggered_EDGE(),
			  "CURRENT TRIGGERED EDGE IS 0 (NULL) !");

	QVERIFY2 (_A_RUNTIME_MONITOR_FOR_TESTING->get_current_triggered_EDGE() == a_root_edge,
			  "CURRENT TRIGGERED EDGE IS NOT MATCHING !");
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::CREATE_A_RUNTIME_MONITOR_STATE_TEST()
{
	YRI_CPP_MONITOR_STATE *_a_test_ut_state;

	_a_test_ut_state =
		_A_RUNTIME_MONITOR_FOR_TESTING->create_yri_monitor_state(E_STATE);

	YRI_QVERIFY2_QSTRING(0 != _a_test_ut_state,
						QString("NO EXISTING STATE: '%1' found !")
							.arg(E_STATE));


	YRI_QVERIFY2_QSTRING
		(YRI_CPP_UTILS::isEqualsCaseInsensitive(E_STATE, _a_test_ut_state->get_MONITOR_STATE_NAME()),
										   QString("RETURNED A WRONG EXISTING STATE: '%1'!")
										   	   .arg(_a_test_ut_state->get_MONITOR_STATE_NAME()));
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::YRI_TRIGGER_guarded_condition_EDGE_TEST()
{
	QList<YRI_CPP_MONITOR_EDGE *> resulting_edges;

	_A_RUNTIME_MONITOR_FOR_TESTING
		->find_yri_monitor_edges(D_STATE,
						  	    E_STATE,
								resulting_edges);

	YRI_QVERIFY2_QSTRING (resulting_edges.size() > 0,
			  	  	  	 QString("COULDN'T FIND A %1 EDGE")
						 	 .arg(D_E_state_transition_EVENT_TOKEN));

	QVERIFY (0 != resulting_edges.at(0));


	QVERIFY (0 == resulting_edges.at(0)->get_guarded_CONDITION_expression());


	YRI_QVERIFY2_QSTRING ((true == resulting_edges.at(0)->evaluate_GUARDED_CONDITION_expression()),
			  	  	  	 QString("GUARDED CONDITION for state transition \"%1\" DOESN'T EVALUATE TO \"True\"")
						 	 .arg(resulting_edges.at(0)->get_guarded_CONDITION_expression__TO_STRING()));
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::YRI_TRIGGER_A_RUNTIME_MONITOR_EDGE_TEST()
{
	_A_RUNTIME_MONITOR_FOR_TESTING->TRACE_LOG_current_RECEIVED_EVENT_TOKEN(D_E_state_transition_EVENT_TOKEN);

	bool AN_EDGE_EVENT_TOKEN_in_trace_log =
				_A_RUNTIME_MONITOR_FOR_TESTING->IS_in_TRACE_LOG(D_E_state_transition_EVENT_TOKEN);

	YRI_QVERIFY2_QSTRING (AN_EDGE_EVENT_TOKEN_in_trace_log,
			  	  	  	 QString("EVENT (edge transition) %1 not found in system trace log")
						 	 .arg(D_E_state_transition_EVENT_TOKEN));


	//++++++++++++++

	bool TRIGGERED = _A_RUNTIME_MONITOR_FOR_TESTING
						->YRI_trigger_an_edge_event(D_E_state_transition_EVENT_TOKEN);


	QVERIFY2 (true == TRIGGERED, "EDGE COULDLN'T BE TRIGGERED");


	YRI_CPP_MONITOR_STATE *a_current_state = _A_RUNTIME_MONITOR_FOR_TESTING->get_current_MONITOR_STATE();

	QVERIFY2 (0 != a_current_state, "[2] CURRENT STATE IS 0 (NULL) !");

	QVERIFY2 (YRI_CPP_UTILS::isEqualsCaseInsensitive(a_current_state->get_MONITOR_STATE_NAME(), E_STATE),
			  QString("CURRENT STATE IS NOT: '%1'")
			  	  .arg(E_STATE).toStdString().c_str());
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::DOT_PRINT_VIEW_RUNTIME_MONITOR_TEST()
{
	QString dot_file_content =
        _A_RUNTIME_MONITOR_FOR_TESTING
            ->print_TO_dot_FILE(false,
                                false);

	QVERIFY (!dot_file_content.isEmpty());
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::DOT_PRINT_2_VIEW_RUNTIME_MONITOR_TEST()
{
	QString dot_file_content =
        _A_RUNTIME_MONITOR_FOR_TESTING
            ->print_TO_dot_FILE("YRI_RUNTIME_TEST_DOT_PRINT",
                                false,
                                false);

	QVERIFY (!dot_file_content.isEmpty());
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::_YRI_EXPORT_CLASSES_headers_TEST()
{
	QString header_FILE_content =
			_A_RUNTIME_MONITOR_FOR_TESTING
				->YRI_generate_cplusplus_headers_files__AND__SAVE__TO__DISK
                    ("yri_sd_mealy_UT-GENERATED.hpp",
                     "A_YRI_SD_MEALY_ut");

	QVERIFY (!header_FILE_content.isEmpty());
//	qDebug() << "header file content: "
//			 << header_FILE_content;
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::_YRI_EXPORT_CLASSES_SOURCES_TEST()
{
	QString SOURCE_FILE_content =
			_A_RUNTIME_MONITOR_FOR_TESTING
				->YRI_generate_cplusplus_sources_files__AND__SAVE__TO__DISK
                    ("yri_sd_mealy_UT-GENERATED.cpp",
                     "A_YRI_SD_MEALY_ut");

	QVERIFY (!SOURCE_FILE_content.isEmpty());
//	qDebug() << "SOURCE FILE CONTENT: "
//			 << SOURCE_FILE_content;
}


void YRI_UTILS_GENERATOR_MONITOR_TEST::FIND_A_RUNTIME_MONITOR_EDGE_TEST()
{
	QVERIFY (0 != _an_edge_TEST);

	QList<YRI_CPP_MONITOR_EDGE *> resulting_edges;

	_A_RUNTIME_MONITOR_FOR_TESTING->find_yri_monitor_edges(*_an_edge_TEST, resulting_edges);

	//qDebug() << "resulting_edges.size(): " << resulting_edges.size();

	QVERIFY (1 == resulting_edges.size());
}



