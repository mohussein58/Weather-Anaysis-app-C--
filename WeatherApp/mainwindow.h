#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void fetchWeatherData(const QString &location, const QString &startDate, const QString &endDate);
    void plotWeatherData(const QJsonObject &weatherData);

public:
    QNetworkAccessManager *networkManager;
    QChartView *chartView;
    QChartView *chartView_1;
    QChartView *chartView_2;
    QChartView *chartView_3;

    QVBoxLayout *layout;
    QVBoxLayout *layout_1;
    QVBoxLayout *layout_2;
    QVBoxLayout *layout_3;

private slots:
    void submitClicked();
    void replyFinished(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
