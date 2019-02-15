#include <QApplication>
#include <qsettings.h>
#include "mainsettingwindow.h"
#include <windows.h>
#include <QMessageBox>



LONG ApplicationCrashHandler(EXCEPTION_POINTERS *pException){//程式异常捕获
    /*
     ***保存数据代码***
    */
    //这里弹出一个错误对话框并退出程序
    EXCEPTION_RECORD* record = pException->ExceptionRecord;
    QString errCode(QString::number(record->ExceptionCode,16)),errAdr(QString::number((uint)record->ExceptionAddress,16)),errMod;
    QMessageBox::critical(nullptr,"程式崩溃","<FONT size=4><div><b>哦豁，蹦了</b><br/></div>"+
        QString("<div>错误代码：%1</div><div>错误地址：%2</div></FONT>").arg(errCode).arg(errAdr),
        QMessageBox::Ok);
    return EXCEPTION_EXECUTE_HANDLER;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);

    QSettings setting("./ElapseData.ini", QSettings::IniFormat);

    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);//注冊异常捕获函数
   MainSettingWindow m;
   m.show();


    return a.exec();
}

