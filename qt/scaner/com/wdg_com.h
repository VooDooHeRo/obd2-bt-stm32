#ifndef WDG_COM_H
#define WDG_COM_H

#include <QString>
#include <QObject>
#include <QSerialPort>

#include "ui_com.h"
#include "msg.h"

class wdg_com_t : public QWidget
{
	Q_OBJECT

	private:

		Ui::com * ui;
		QSerialPort sp;

		QString log;
		QByteArray ba;
		uint8_t rx_state;

	private:
		QByteArray get_msg(char ch);
		void stop();

	private slots:
		void serial_read_cb();
		void slt_error(QSerialPort::SerialPortError error);
		void slt_open();

	public slots:
		void slt_msg(const QByteArray &);

	signals:
		void sig_opened();
		void sig_closed();
		void sig_log(uint8_t, const QString & log);
		void sig_msg(const QByteArray &);

	public:
		wdg_com_t(QWidget * parent = 0);
		~wdg_com_t();
};

#endif

