/*
 * YRI_UTILS_GENERATOR_MONITOR_TEST.hpp
 *
 *      Author: Pr. Prof. Dr.-Ing. XAVIER Noumbissi NOUNDOU
 */


#ifndef YRI_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_
#define YRI_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_


#include "../yri_sd_runtime_verif/src/YRI_CPP_MONITOR_EDGE.hpp"

#include "../yri_sd_runtime_verif/src/YRI_CPP_MONITOR.hpp"


#include <QtTest/QtTest>

#include <QtCore/QObject>

#include <QtCore/QDebug>


class YRI_UTILS_GENERATOR_MONITOR_TEST : public QObject
{
	Q_OBJECT

public:

	void initTestCase();

	void cleanupTestCase();

	YRI_UTILS_GENERATOR_MONITOR_TEST()
	{
	}

	virtual ~YRI_UTILS_GENERATOR_MONITOR_TEST();

private slots:

	void CREATE_A_RUNTIME_MONITOR_TEST();

	void CREATE_A_RUNTIME_MONITOR_EDGE_TEST();

	void CREATE_A_RUNTIME_MONITOR_STATE_TEST();

	void FIND_A_RUNTIME_MONITOR_EDGE_TEST();

	void YRI_TRIGGER_guarded_condition_EDGE_TEST();

	void YRI_TRIGGER_A_RUNTIME_MONITOR_EDGE_TEST();

	void DOT_PRINT_VIEW_RUNTIME_MONITOR_TEST();

	void DOT_PRINT_2_VIEW_RUNTIME_MONITOR_TEST();

	void _YRI_EXPORT_CLASSES_headers_TEST();

	void _YRI_EXPORT_CLASSES_SOURCES_TEST();

protected:

	static QString C_STATE;

	static QString D_STATE;

	static QString E_STATE;

	static QString C_D_state_transition_EVENT_TOKEN;

	static QString D_E_state_transition_EVENT_TOKEN;

	static YRI_CPP_MONITOR_STATE *_a_root_STATE;

	static YRI_CPP_MONITOR_EDGE *_an_edge_TEST;

	static YRI_CPP_MONITOR *_A_RUNTIME_MONITOR_FOR_TESTING;
};


#define YRI_QVERIFY2_QSTRING(B, QS) QVERIFY2(B, GET_C_STR_FROM_QSTRING(QS))


#endif //YRI_SD_RUNTIME_VERIF_UNIT_TEST_GENERATOR_TEST_HPP_


