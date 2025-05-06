#include <QObject>
#include <QJSValue>
#include <QProcess>
#include <QHash>
#include <QPair>

class UtilTools: public QObject
{
    Q_OBJECT

public:
    UtilTools(QObject *parent = 0);
    virtual ~UtilTools();

    Q_INVOKABLE void cleanRpmDb(QJSValue successCallback = QJSValue::UndefinedValue,
                                QJSValue errorCallback = QJSValue::UndefinedValue);

    Q_INVOKABLE void cleanLocalsearchDb(QJSValue successCallback = QJSValue::UndefinedValue,
                                        QJSValue errorCallback = QJSValue::UndefinedValue);

    Q_INVOKABLE void restartNetwork(QJSValue successCallback = QJSValue::UndefinedValue,
                                    QJSValue errorCallback = QJSValue::UndefinedValue);

    Q_INVOKABLE void restartBluetooth(QJSValue successCallback = QJSValue::UndefinedValue,
                                      QJSValue errorCallback = QJSValue::UndefinedValue);

    Q_INVOKABLE void restartLipstick(QJSValue successCallback = QJSValue::UndefinedValue,
                                     QJSValue errorCallback = QJSValue::UndefinedValue);

    Q_INVOKABLE void restartFingerprint(QJSValue successCallback = QJSValue::UndefinedValue,
                                        QJSValue errorCallback = QJSValue::UndefinedValue);

private slots:
    void handleProcessExit(int exitCode, QProcess::ExitStatus status);

private:
    void execute(const QString &command, const QStringList &arguments,
                 QJSValue successCallback, QJSValue errorCallback);

    QHash<QProcess*, QPair<QJSValue, QJSValue> > m_pendingCalls;
};
