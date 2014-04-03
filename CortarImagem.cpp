#include "StdAfx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat cortarImagem(Mat imagem, int x, int y , int xfim, int yfim){
	 Rect myRoi(x, y, xfim, yfim);
	 Mat croppedImage = imagem(myRoi);
	 Mat(imagem, myRoi).copyTo(croppedImage);
	 return croppedImage;
}

int main( int argc, const char** argv )
{
	//Inicializar parámetros da borda (em pixels)
	int x; // posição x superior esquerda
	int y; // posição y superior esquerda
	int xfim; // posição x inferior direita
	int ygim; // posição y inferior direita

	//Ler archivos de uma pasta
	String fonte="D:/mamografias"; //argv[0] 
	String destino="D:/processado"; //argv[1] 

	//criar código para ler os arquivo da pasta
		
		//Para cada arquivo fazer
		string imagemAtual="termograma.jpg"; //recupera a imagem atual do ar
		Mat img = imread(imagemAtual, CV_LOAD_IMAGE_COLOR); //Abrir uma imagem na variavel img

		if (img.empty()) //conferir se a imagem foi carregada
		{
			cout << "Erro : A imagem não foi carregada..!!" << endl;
			//system("pause"); 
		}

		// cortar a imagem
		Mat croppedImage = cortarImagem(img, 50, 50,img.cols-50,  img.rows-50);

		//namedWindow("Saida", CV_WINDOW_AUTOSIZE); 
		//imshow("Saida", croppedImage); 
	 

	waitKey(0); 
	//destroyWindow("Principal"); 
	system("pause"); 
	return 0;
}