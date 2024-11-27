#include "demo.h"
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/imgproc.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <filesystem>
#include <fstream>

using namespace cv;
using namespace std;

double maximys = -1, tmp_0;

Demo::Demo(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QHBoxLayout* xLayout = new QHBoxLayout;
    QLabel* xLabel = new QLabel("X1:", this);
    xLineEdit = new QLineEdit(this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xLineEdit);

    QHBoxLayout* yLayout = new QHBoxLayout;
    QLabel* yLabel = new QLabel("Y1:", this);
    yLineEdit = new QLineEdit(this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yLineEdit);

    QHBoxLayout* widthLayout = new QHBoxLayout;
    QLabel* widthLabel = new QLabel("X2:", this);
    widthLineEdit = new QLineEdit(this);
    widthLayout->addWidget(widthLabel);
    widthLayout->addWidget(widthLineEdit);

    QHBoxLayout* heightLayout = new QHBoxLayout;
    QLabel* heightLabel = new QLabel("Y2:", this);
    heightLineEdit = new QLineEdit(this);
    heightLayout->addWidget(heightLabel);
    heightLayout->addWidget(heightLineEdit);

    QHBoxLayout* pathLayout = new QHBoxLayout;
    QLabel* pathLabel = new QLabel(tr("Path:"), this);
    pathLineEdit = new QLineEdit(this);
    pathLayout->addWidget(pathLabel);
    pathLayout->addWidget(pathLineEdit);

    loadButton = new QPushButton(tr("Select Directory"), this);
    executeButton = new QPushButton(tr("Accomplishment"), this);

    resultLabel = new QLabel(tr(" "), this);
    mainLayout->addWidget(resultLabel);

    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(executeButton);

    mainLayout->addLayout(xLayout);
    mainLayout->addLayout(yLayout);
    mainLayout->addLayout(widthLayout);
    mainLayout->addLayout(heightLayout);
    mainLayout->addLayout(pathLayout);
    mainLayout->addWidget(loadButton);
    mainLayout->addLayout(buttonLayout);

    connect(loadButton, &QPushButton::clicked, this, &Demo::onLoadButtonClicked);
    connect(executeButton, &QPushButton::clicked, this, &Demo::onExecuteButtonClicked);
}

void Demo::onLoadButtonClicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"), QDir::homePath());
    if (!dirPath.isEmpty())
    {
        pathLineEdit->setText(dirPath);
    }
}

void Demo::onExecuteButtonClicked()
{
    bool xOk, yOk, widthOk, heightOk;
    int x = xLineEdit->text().toInt(&xOk);
    int y = yLineEdit->text().toInt(&yOk);
    int width = widthLineEdit->text().toInt(&widthOk);
    int height = heightLineEdit->text().toInt(&heightOk);
    QString path = pathLineEdit->text();

    if (xOk && yOk && widthOk && heightOk && !path.isEmpty())
    {
        executeAction(x, y, width, height, path);
    }
    else
    {
        QMessageBox::warning(this, tr("Input Error"), tr("Please provide valid input for all fields."));
    }
}

void Demo::executeAction(int x, int y, int width, int height, const QString& path)
{
    using namespace std::filesystem;

    string reference(Mat image, int x, int y, int width, int height);
    void search_by_reference(Mat image, string ref, const QString & newDirPath, int i, const QString & baseName, const QString & extension);
    string Friman(vector<Point> points);
    int Comparison(string F, string F_o);
    void alignImages(Mat & im1, Mat & im2, Mat & im1Reg, Mat & h, const QString & newDirPath, const QString & baseName, int i, const QString & extension);

    // Путь к каталогу
    QDir directory(path);
    QFileInfoList fileList = directory.entryInfoList(QDir::Files);

    // Создайте новый каталог с добавлением "rez" к его названию
    QString newDirPath = directory.absolutePath() + "_rez";
    QDir newDir(newDirPath);
    if (!newDir.exists()) {
        newDir.mkpath(".");
    }

    // Проверка на наличие файлов
    if (!fileList.isEmpty()) {

        // Определение первого файла для нормализации
        QString filename_ref = fileList.first().absoluteFilePath();
        Mat image_ref = imread(filename_ref.toStdString());
        string ref = reference(image_ref, x, y, width, height);

        // Обработка всех файлов
        for (int i = 0; i < fileList.size(); ++i) {
           
            QString filename = fileList.at(i).absoluteFilePath();
            Mat image = imread(filename.toStdString()); // Текущее изображение
            //imshow("original", image);
            if (i == 0) {
                
            }
            // Получение базового имени и расширения
            QFileInfo fileInfo(filename);
            QString baseName = fileInfo.completeBaseName();
            QString extension = fileInfo.suffix();

            Mat imReg, h, imageGayss, image_ref_Gayss;
            medianBlur(image, imageGayss, 3);
            medianBlur(image_ref, image_ref_Gayss, 3);
            namedWindow("reference", WINDOW_NORMAL);
            imshow("reference", imageGayss);
            alignImages(imageGayss, image_ref_Gayss, imReg, h, newDirPath, baseName, i, extension);
            //поиск в соответствии с эталоном
            search_by_reference(imReg, ref, newDirPath, i, baseName, extension); // Updated call
            // tmp_0 = Comparison

            ofstream file("Accordance.txt", std::ios::app);
            file << baseName.toStdString() << ": " << maximys << "\n";
            file.close();

            /*QString status = QString(tr("Accordance = %1")).arg(maximys);
            QMessageBox::information(this, ("Info"), status);*/
            maximys = -1;
        }

        resultLabel->setText(tr("The percentage of match with the standard is saved in the file Accordance.txt"));

        QMessageBox::information(this, tr("Processing completed"), tr("All files successfully processed."));
    
    } else QMessageBox::warning(this, tr("Input Error"), tr("No files found"));
}

//Реализация Фримана
string Friman(vector<Point> points) {
    string array{};

    for (int i = 1; (i < points.size()); i++) {
        if (points[i].x - points[i - 1].x == 1) {
            //right
            switch (points[i].y - points[i - 1].y) {
            case(1):
                array = array + '3';
                break;
            case(0):
                array = array + '2';
                break;
            case(-1):
                array = array + '1';
                break;
            }
        }
        else if (points[i].x - points[i - 1].x == -1) {
            //left
            switch (points[i].y - points[i - 1].y) {
            case(1):
                array = array + '5';
                break;
            case(0):
                array = array + '6';
                break;
            case(-1):
                array = array + '7';
                break;
            }
        }
        else  if (points[i].y - points[i - 1].y == 1) {
            // up
            array = array + '4';
        }
        else {
            //down
            array = array + '0';
        }
    }

    return array;
}

//Подсчет кличества совпадений 
double Comparison(string F, string F_o) {
    int a0 = 0, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0;
    int A[8] = {}, B[8] = {}, tmp=0;
    /*for (int i = 0; (i < F_o.size()) && (i < F.size()); i++) {
        if (F[i] == F_o[i]) k++;
    }*/
    for (int i = 0; i < F_o.size(); i++) {
        if (F_o[i]-'0' == 0) A[0] = A[0] + 1;
        else if (F_o[i] - '0' == 1) A[1] = A[1] + 1;
        else if (F_o[i] - '0' == 2) A[2] = A[2] + 1;
        else if (F_o[i] - '0' == 3) A[3] = A[3] + 1;
        else if (F_o[i] - '0' == 4) A[4] = A[4] + 1;
        else if (F_o[i] - '0' == 5) A[5] = A[5] + 1;
        else if (F_o[i] - '0' == 6) A[6] = A[6] + 1;
        else if (F_o[i] - '0' == 7) A[7] = A[7] + 1;
        tmp=F_o[0] - '0';
    }
    for (int i = 0; i < F.size(); i++) {
        if (F[i] == 0) B[0] = B[0] + 1;
        else if (F[i] - '0' == 1) B[1] = B[1] + 1;
        else if (F[i] - '0' == 2) B[2] = B[2] + 1;
        else if (F[i] - '0' == 3) B[3] = B[3] + 1;
        else if (F[i] - '0' == 4) B[4] = B[4] + 1;
        else if (F[i] - '0' == 5) B[5] = B[5] + 1;
        else if (F[i] - '0' ==6) B[6] = B[6] + 1;
        else if (F[i] - '0'== 7) B[7] = B[7] + 1;
    }
    int c2 = 0, b2 = 0, cb = 0;
    double k = 0;
    for (int l = 0; l <= 7; l++) {
        c2 = c2 + A[l]* A[l];
        b2 = b2 + B[l]* B[l];
        cb = cb + B[l] * A[l];
    }
    k = cb / (sqrt(c2) * sqrt(b2));
    return k;
}

//Выделение контура эталона
string reference(Mat image, int x, int y, int width, int height) {

    Mat gray_o, dst_o1, dst_o, frim_o;

    Rect roi(x, y, width-x, height-y);
    Mat image_o = image;


    image_o = image_o(roi);
    cvtColor(image_o, gray_o, COLOR_BGR2GRAY);
    Canny(gray_o, dst_o1, 80, 100, 3);
    dilate(dst_o1, dst_o, Mat(), Point(-1, -1), 2, 1, 1); //расширение границы, чтобы соединить края 

    vector<vector<Point>>points_o;
    vector<Vec4i>hierarchy_o;
    findContours(dst_o, points_o, hierarchy_o, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    frim_o = Mat::zeros(dst_o.size(), CV_8UC3);
    for (int i = 0; (i < hierarchy_o.size()); i++)
    {
        Scalar color = Scalar(255, 255, 255);
        drawContours(frim_o, points_o, i, color, 2, 1);
    }

    //namedWindow("reference", WINDOW_NORMAL);
    //namedWindow("FrimCont_reference", WINDOW_NORMAL);
    //imshow("reference", image_o);
    //imshow("FrimCont_reference", frim_o);
    //imwrite("reference.jpg", image_o);
    //imwrite("Canny_reference.jpg", dst_o);
    //imwrite("FrimCont_reference.jpg", frim_o);

    int max_j = -1, max = -1;
    for (int j = 0; (j < hierarchy_o.size()); j++) {
        int a = points_o[j].size();
        if (a >= max) {
            max = a;
            max_j = j;
        }
    }

    string ref = Friman(points_o[max_j]);
    return ref;
}

//Поиск в соответствии с эталоном
void search_by_reference(Mat image, string ref, const QString& newDirPath, int i, const QString& baseName, const QString& extension) {

    Mat gray, dst, dst1, frim, frim_all; // градация серого и контуры
    // преобразуем в градации серого
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // границы по Канни
    Canny(gray, dst1, 80, 100, 3);

    dilate(dst1, dst, Mat(), Point(-1, -1), 2, 1, 1);     //Расширение, с целью предотвращения разрывов

    vector<vector<Point>>points;
    vector<Vec4i>hierarchy;

    //Поиск контуров
    findContours(dst, points, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    // Рисуем контур
    Point2f center;
    float radius = 0;

    int  maximus_i = -1;
    frim = Mat::zeros(dst.size(), CV_8UC3);
    frim_all = Mat::zeros(dst.size(), CV_8UC3);
    for (int i = 0; (i < hierarchy.size()); i++)
    {
        Scalar color = Scalar(255, 255, 255);
        drawContours(frim_all, points, i, color, 2, 1);
        string F = Friman(points[i]);
        double k = Comparison(F, ref);
        if ((k >= maximys)) {
            maximys = k;
            maximus_i = i;
        }
    }
    String FrimanP = Friman(points[maximus_i]);
    Scalar color = Scalar(255, 255, 255);
    drawContours(frim, points, maximus_i, color, 2, 1);
    //QMessageBox::information(this, maximys);
    //minEnclosingCircle(points[maximus_i], center, radius);
   // circle(frim, center, radius, CV_RGB(255, 255, 255), 1, 8); //переменная center и передает координаты середины нашего объекта!

    //Сохранение файлов в новой папке
    QString frimPath = newDirPath + "/" + baseName + QString("_%1.").arg(i) + extension;
    QString frimAllPath = newDirPath + "/" + baseName + QString("_all_contours_by_Freeman_%1.").arg(i) + extension;
    QString cannyPath = newDirPath + "/" + baseName + QString("_all_contours_by_Canny_%1.").arg(i) + extension;
    //QString frimCannyPath = newDirPath + "/" + baseName + QString("_Canny_%1.").arg(i) + extension;

    imwrite(frimPath.toStdString(), frim);
    imwrite(frimAllPath.toStdString(), frim_all);
    imwrite(cannyPath.toStdString(), dst);
    //imwrite(frimCannyPath.toStdString(), dst);
}

const int MAX_FEATURES = 500;
const float GOOD_MATCH_PERCENT = 0.15f;
void alignImages(Mat& im1, Mat& im2, Mat& im1Reg, Mat& h, const QString& newDirPath,  const QString& baseName, int n, const QString& extension) {

    // Объявление переменных для ключевых точек и дескрипторов
    std::vector<KeyPoint> keypoints1, keypoints2;
    Mat descriptors1, descriptors2;

    // Создание объекта ORB, обнаружение признаков и вычисления дескрипторов
    Ptr<Feature2D> orb = ORB::create(MAX_FEATURES);
    orb->detectAndCompute(im1, Mat(), keypoints1, descriptors1);
    orb->detectAndCompute(im2, Mat(), keypoints2, descriptors2);

    // Match features.
    std::vector<DMatch> matches;
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
    //Сопоставление дескрипторов и хранение совпадений
    matcher->match(descriptors1, descriptors2, matches, Mat());

    // Сортировка совпадений по качеству
    std::sort(matches.begin(), matches.end());

    // Удаление неподходящих совпадений
    const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
    matches.erase(matches.begin() + numGoodMatches, matches.end());
    //Поиск специфических совпадений (верхний, левый и правый)
    {
        std::vector<DMatch> tMatches = matches;
        //find up
        DMatch upMatch, leftMatch, rigthMatch;
        Point2f upPointF, upPointS;
        double y = LONG_MIN;
        for (int i = 0; i < matches.size(); i++)
        {
            if (keypoints1[matches[i].queryIdx].pt.y > y) {
                upMatch = matches[i];
                y = keypoints1[matches[i].queryIdx].pt.y;
            }
        }
        //left
        double x = keypoints1[upMatch.queryIdx].pt.x;
        y = keypoints1[upMatch.queryIdx].pt.y;

        for (int i = 0; i < matches.size(); i++)
        {
            if (keypoints1[matches[i].queryIdx].pt.x < x
                && keypoints1[matches[i].queryIdx].pt.y < y) {
                leftMatch = matches[i];
                break;
            }
        }
        for (int i = 0; i < matches.size(); i++)
        {
            if (keypoints1[matches[i].queryIdx].pt.x > x
                && keypoints1[matches[i].queryIdx].pt.y < y) {
                rigthMatch = matches[i];
                break;
            }
        }
        std::vector<DMatch> tempMatches;

        tempMatches.push_back(upMatch);
        tempMatches.push_back(leftMatch);
        tempMatches.push_back(rigthMatch);

        Mat imMatches;
        std::vector<KeyPoint> tkeypoints1, tkeypoints2;

        tkeypoints2.push_back(keypoints1[upMatch.queryIdx]);
        tkeypoints2.push_back(keypoints1[leftMatch.queryIdx]);
        tkeypoints2.push_back(keypoints1[rigthMatch.queryIdx]);

        tkeypoints1.push_back(keypoints2[upMatch.trainIdx]);
        tkeypoints1.push_back(keypoints2[leftMatch.trainIdx]);
        tkeypoints1.push_back(keypoints2[rigthMatch.trainIdx]);

        drawMatches(im1, keypoints1, im2, keypoints2, tempMatches, imMatches);
        QString matches2 = newDirPath + "/" + baseName + QString("_matches2_%1.").arg(n) + extension;
        imwrite(matches2.toStdString(), imMatches);
    }
    // Отображение лучших совпадений
    Mat imMatches;
    drawMatches(im1, keypoints1, im2, keypoints2, matches, imMatches);
    //QString matches1 = newDirPath + "/" + baseName + QString("_matches1_%1.").arg(n) + extension;
    //imwrite(matches1.toStdString(), imMatches);

    // Извлечение координат хороших совпадений
    std::vector<Point2f> points1, points2;

    for (size_t i = 0; i < matches.size(); i++)
    {
        points1.push_back(keypoints1[matches[i].queryIdx].pt);
        points2.push_back(keypoints2[matches[i].trainIdx].pt);
    }

    // Вычисление гомографии
    h = findHomography(points1, points2, RANSAC);

    // Преобразование изображения с использованием гомографии
    warpPerspective(im1, im1Reg, h, im2.size());
}