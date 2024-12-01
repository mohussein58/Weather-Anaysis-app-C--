#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->submitBtn, &QPushButton::clicked, this, &MainWindow::submitClicked);

    // Initialize network manager
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::replyFinished);

    layout = new QVBoxLayout(ui->chartWidget); // Create a layout for the chart widget
    layout_1 = new QVBoxLayout(ui->humidityWidget); // Create a layout for the chart widget
    layout_2 = new QVBoxLayout(ui->precipWidget); // Create a layout for the chart widget
    layout_3 = new QVBoxLayout(ui->windWidget); // Create a layout for the chart widget

    ui->chartWidget->setLayout(layout);
    ui->chartWidget->setLayout(layout_1);
    ui->chartWidget->setLayout(layout_2);
    ui->chartWidget->setLayout(layout_3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::submitClicked(){
    QString location = ui->Location->text();
    QString startDate = ui->startDate->text();
    QString endDate = ui->endDate->text();


    if (location.isEmpty()) {
        QMessageBox::critical(this, "Error", "Location is required!");
        return;
    }

    fetchWeatherData(location, startDate, endDate);
}

void MainWindow::fetchWeatherData(const QString &location, const QString &startDate, const QString &endDate) {
    QString baseUrl = "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/";
    QString url;
    QString API_KEY = QString("3KAJKHWT3UEMRQWF2ABKVVVZE");
    if (!endDate.isEmpty())
        url = baseUrl + location + "/" + startDate + "/" + endDate + "?key=" + API_KEY;
    else if (!startDate.isEmpty())
        url = baseUrl + location + "/" + startDate + "?key=" + API_KEY;
    else
        url = baseUrl + location + "?key=" + API_KEY;

    QNetworkRequest request(url);
    networkManager->get(request);
}

void MainWindow::replyFinished(QNetworkReply *reply) {

    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "Error", "Failed to fetch data: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        QMessageBox::critical(this, "Error", "Failed to parse JSON data.");
        return;
    }

    plotWeatherData(doc.object());

}


void MainWindow::plotWeatherData(const QJsonObject &weatherData) {
    // Create a chart object
    QChart *temp_chart = new QChart();
    temp_chart->setTitle("Daily Temperature");
    temp_chart->setAnimationOptions(QChart::AllAnimations);

    QChart *humidity_chart = new QChart();
    humidity_chart->setTitle("Daily Humidity");
    humidity_chart->setAnimationOptions(QChart::AllAnimations);

    QChart *precip_chart = new QChart();
    precip_chart->setTitle("Daily Precipitation");
    precip_chart->setAnimationOptions(QChart::AllAnimations);

    QChart *wind_chart = new QChart();
    wind_chart->setTitle("Daily Wind Speed");
    wind_chart->setAnimationOptions(QChart::AllAnimations);

    // Create a line series and add data
    QLineSeries *series = new QLineSeries();
    QLineSeries *series_1 = new QLineSeries();
    QLineSeries *series_2 = new QLineSeries();
    QLineSeries *series_3 = new QLineSeries();


    QJsonArray entries = weatherData["days"].toArray();
    for (const QJsonValue &value : entries) {
        QJsonObject obj = value.toObject();
        QDateTime time = QDateTime::fromString(obj["datetime"].toString(), Qt::ISODate);
        double temperature = obj["temp"].toDouble();
        double humidity = obj["humidity"].toDouble();
        double precip = obj["precip"].toDouble();
        double wind = obj["windspeed"].toDouble();

        series->append(time.toMSecsSinceEpoch(), temperature); // Use actual datetime values
        series_1->append(time.toMSecsSinceEpoch(), humidity);
        series_2->append(time.toMSecsSinceEpoch(), precip);
        series_3->append(time.toMSecsSinceEpoch(), wind);
    }

    temp_chart->addSeries(series);
    humidity_chart->addSeries(series_1);
    precip_chart->addSeries(series_2);
    wind_chart->addSeries(series_3);

    // Create axes
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTitleText("Time");

    QDateTimeAxis *axisX_1 = new QDateTimeAxis();
    axisX->setTitleText("Time");

    QDateTimeAxis *axisX_2 = new QDateTimeAxis();
    axisX->setTitleText("Time");

    QDateTimeAxis *axisX_3 = new QDateTimeAxis();
    axisX->setTitleText("Time");

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Temperature (°C)");

    QValueAxis *axisY_1 = new QValueAxis();
    axisY->setTitleText("Humidity (%)");

    QValueAxis *axisY_2 = new QValueAxis();
    axisY->setTitleText("Precipitation (mm)");

    QValueAxis *axisY_3 = new QValueAxis();
    axisY->setTitleText("Wind Speed (km/h)");

    temp_chart->setAxisX(axisX, series);
    temp_chart->setAxisY(axisY, series);

    humidity_chart->setAxisX(axisX_1, series_1);
    humidity_chart->setAxisY(axisY_1, series_1);

    precip_chart->setAxisX(axisX_2, series_2);
    precip_chart->setAxisY(axisY_2, series_2);

    wind_chart->setAxisX(axisX_3, series_3);
    wind_chart->setAxisY(axisY_3, series_3);

    if (chartView != NULL){
        layout->removeWidget(chartView);
        layout_1->removeWidget(chartView_1);
        layout_2->removeWidget(chartView_2);
        layout_3->removeWidget(chartView_3);
    }

    chartView = new QChartView(temp_chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(chartView);

    chartView_1 = new QChartView(humidity_chart);
    chartView_1->setRenderHint(QPainter::Antialiasing);
    layout_1->addWidget(chartView_1);

    chartView_2 = new QChartView(precip_chart);
    chartView_2->setRenderHint(QPainter::Antialiasing);
    layout_2->addWidget(chartView_2);

    chartView_3 = new QChartView(wind_chart);
    chartView_3->setRenderHint(QPainter::Antialiasing);
    layout_3->addWidget(chartView_3);

}




