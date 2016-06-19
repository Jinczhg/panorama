#ifndef _API_H
#define _API_H

#include "../bottom/bottom.h"

#define SCALE			(10.)				//���ű���
#define ACCURACY_BIT		10				//���㾫��λ��
#define ACCURACY_NUM		1024			//���㾫�ȴ�С
#define ACCURACY_POINT		0x000003FF		//���㾫��С������

#define WeightAccuracyBit   8				//Ȩֵ���㾫��λ��
#define WeightAccuracNum	256				//Ȩֵ���ȴ�С
#define WeightAccuracyPoint 0x000000FF		//Ȩֵ����С������


//ƴ�����õ�����Ϣ
typedef struct{
	IplImage		*srcImage;				//�����Դͼ��
	IplImage		*undistorImage;			//У�����͸��ͼ
	IplImage		*birdImage;				//����ͼ
	IplImage		*transformImage;		//������ӳ�䵽ȫ��ͼ
	IplImage		*stitchImage;			//ȫ��ͼ

	IplImage		*mapx;					//����У��X�����
	IplImage		*mapy;					//����У��Y�����

	CvPoint2D32f	*srcCorners;			//Դͼ�����̸�����
	CvPoint2D32f	*birdCorners;			//����ͼ�����̸�����

	CvPoint2D32f	*srcMarkPoint;			//��ǵ�������̸������
	CvPoint2D32f	*birdMarkPoint;			//����ͼ�б�ǵ�����
	CvPoint2D32f	*stitchMarkPoint;		//ȫ��ͼ�б�ǵ�����
	
	CvPoint2D32f	*stitchPoint;			//ȫ��ͼ�и������������ֵĶ���
	/*1---------------------------2*/		
	/*|							  |*/		
	/*|			ǰ��			  |*/
	/*|			stitchPoint		  |*/
	/*0\		���			 /3  */
	/*	\						/   */
	/*	 \5-------------------4/  */

	int				nboard_w;				//����ˮƽ���������
	int				nboard_h;				//���̴�ֱ���������
	float			fboardwidth;			//����ˮƽ�������ʵ�ʳ���
	float			fboardheight;			//����ˮƽ�������ʵ�ʳ���

	CvMat			*birdMat;				//͸��ͼ������ͼ��ӳ�����
	CvMat			*stitchMat;				//����ͼ��ƴ��ͼ��ӳ�����
}StitchInfo, *pStitchInfo;

/************************************************************************/
/*				��ʼ��ƴ�Ӳ���                                          */
/************************************************************************/
bool InitParam(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				��ȡ����ͼ                                              */
/************************************************************************/
bool GetBirdImage(StitchInfo *stInfo);
/************************************************************************/
/*				�����ǵ�                                              */
/************************************************************************/
bool GetMarkPoint(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*              ƴ��                                                     */
/************************************************************************/
bool StitchImage(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				�ͷ�ƴ�Ӳ����ڴ�		                                */
/************************************************************************/
bool ReleaseParam(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				���ȫ������û���ںϴ����ģ�                            */
/************************************************************************/
bool WriteStitchMap(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				���ȫ����(�����ںϴ����ģ�                             */
/************************************************************************/
bool WriteStitchMap2(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				��ʼ��ƴ�ӱ�                                            */
/*              ����ȫ��������ȫ��ͼ                                    */
/*				float *frontcoordinatexMat: ǰ��X�����					*/
/*				float *frontcoordinateyMat: ǰ��Y�����					*/
/*				float *frontweightMat:		ǰ��Ȩֵ��					*/
/*				float *rearcoordinatexMat:	����X�����					*/
/*				float *rearcoordinateyMat:	����Y�����					*/
/*				float *rearweightMat:		����Ȩֵ��					*/
/*				float *leftcoordinatexMat:	����X�����					*/
/*				float *leftcoordinateyMat:	����Y�����					*/
/*				float *leftweightMat:		����Ȩֵ��					*/
/*				float *rightcoordinatexMat: ����X�����					*/
/*				float *rightcoordinateyMat: ����Y�����					*/
/************************************************************************/
bool InitStitchMap(float **frontcoordinatexMat, float **frontcoordinateyMat, float **frontweightMat, float **rearcoordinatexMat, float **rearcoordinateyMat,
	float **rearweightMat, float **leftcoordinatexMat, float **leftcoordinateyMat, float **leftweightMat, float **rightcoordinatexMat, float **rightcoordinateyMat, 
	float **rightweightMat);
/************************************************************************/
/*				���̵߳���												*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				float *frontcoordinatexMat: ǰ��X�����					*/
/*				float *frontcoordinateyMat: ǰ��Y�����					*/
/*				float *frontweightMat:		ǰ��Ȩֵ��					*/
/*				float *rearcoordinatexMat:	����X�����					*/
/*				float *rearcoordinateyMat:	����Y�����					*/
/*				float *rearweightMat:		����Ȩֵ��					*/
/*				float *leftcoordinatexMat:	����X�����					*/
/*				float *leftcoordinateyMat:	����Y�����					*/
/*				float *leftweightMat:		����Ȩֵ��					*/
/*				float *rightcoordinatexMat: ����X�����					*/
/*				float *rightcoordinateyMat: ����Y�����					*/
/*				float *rightweightMat:		����Ȩֵ��					*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/************************************************************************/
bool GetStitchImage(float *frontcoordinatexMat, float *frontcoordinateyMat, float *frontweightMat, float *rearcoordinatexMat, float *rearcoordinateyMat,
	float *rearweightMat, float *leftcoordinatexMat, float *leftcoordinateyMat, float *leftweightMat, float *rightcoordinatexMat, float *rightcoordinateyMat, 
	float *rightweightMat, unsigned char *frontImage,  unsigned char *rearImage,  unsigned char *leftImage,  unsigned char *rightImage,  
	unsigned char *stitchImage);
/************************************************************************/
/*				�ͷ�ƴ�ӱ�		                                        */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/*				unsigned int *rightweightMat:		����Ȩֵ��			*/
/************************************************************************/
bool ReleaseStitchMap(unsigned int **frontcoordinatexMat, unsigned int **frontcoordinateyMat, unsigned int **frontweightMat, unsigned int **rearcoordinatexMat, 
	unsigned int **rearcoordinateyMat, unsigned int **rearweightMat, unsigned int **leftcoordinatexMat, unsigned int **leftcoordinateyMat, 
	unsigned int **leftweightMat, unsigned int **rightcoordinatexMat, unsigned int **rightcoordinateyMat, unsigned int **rightweightMat);
/************************************************************************/
/*				���̵߳���												*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				float *frontcoordinatexMat: ǰ��X�����					*/
/*				float *frontcoordinateyMat: ǰ��Y�����					*/
/*				float *frontweightMat:		ǰ��Ȩֵ��					*/
/*				float *rearcoordinatexMat:	����X�����					*/
/*				float *rearcoordinateyMat:	����Y�����					*/
/*				float *rearweightMat:		����Ȩֵ��					*/
/*				float *leftcoordinatexMat:	����X�����					*/
/*				float *leftcoordinateyMat:	����Y�����					*/
/*				float *leftweightMat:		����Ȩֵ��					*/
/*				float *rightcoordinatexMat: ����X�����					*/
/*				float *rightcoordinateyMat: ����Y�����					*/
/*				float *rightweightMat:		����Ȩֵ��					*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/*				int xoffset:				x����ƫ����					*/
/*				int yoffset:				y����ƫ����					*/
/*				int dstwidthstep:			��ʾ����ʾ���Ŀ�			*/
/*				int NX:						ˮƽ���򱻷ֳ�NX����		*/
/*				int NY:						��ֱ���򱻷ֳ�NY����		*/
/************************************************************************/
bool GetStitchImage2(float *frontcoordinatexMat, float *frontcoordinateyMat, float *frontweightMat, float *rearcoordinatexMat, float *rearcoordinateyMat,
	float *rearweightMat, float *leftcoordinatexMat, float *leftcoordinateyMat, float *leftweightMat, float *rightcoordinatexMat, float *rightcoordinateyMat, 
	float *rightweightMat, unsigned char *frontImage,  unsigned char *rearImage,  unsigned char *leftImage,  unsigned char *rightImage,  
	unsigned char *stitchImage, int xoffset, int yoffset, int dstwidthstep, int NX, int NY);
/************************************************************************/
/*				���̵߳���(��������)									*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/*				int xoffset:				x����ƫ����					*/
/*				int yoffset:				y����ƫ����					*/
/*				int dstwidthstep:			��ʾ����ʾ���Ŀ�			*/
/*				int NX:						ˮƽ���򱻷ֳ�NX����		*/
/*				int NY:						��ֱ���򱻷ֳ�NY����		*/
/************************************************************************/
bool GetStitchImage3(unsigned int *frontcoordinatexMat, unsigned int *frontcoordinateyMat, unsigned int *frontweightMat, unsigned int *rearcoordinatexMat, 
	unsigned int *rearcoordinateyMat, unsigned int *rearweightMat, unsigned int *leftcoordinatexMat, unsigned int *leftcoordinateyMat, unsigned int *leftweightMat, 
	unsigned int *rightcoordinatexMat, unsigned int *rightcoordinateyMat, unsigned int *rightweightMat, unsigned char *frontImage,  unsigned char *rearImage,  
	unsigned char *leftImage,  unsigned char *rightImage,  	unsigned char *stitchImage, int xoffset, int yoffset, int dstwidthstep, int NX, int NY);
/************************************************************************/
/*				��ʼ��ƴ�ӱ�(�������㣩                                 */
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/************************************************************************/
bool InitStitchMap2(unsigned int **frontcoordinatex, unsigned int **frontcoordinatey, unsigned int **frontweight, unsigned int **rearcoordinatex, 
	unsigned int **rearcoordinatey, unsigned int **rearweight, unsigned int **leftcoordinatex, unsigned int **leftcoordinatey, unsigned int **leftweight, 
	unsigned int **rightcoordinatex, unsigned int **rightcoordinatey, unsigned int **rightweight);

bool GetStitchImage4(unsigned int *frontcoordinatexMat, unsigned int *frontcoordinateyMat, unsigned int *frontweightMat, unsigned int *rearcoordinatexMat, 
	unsigned int *rearcoordinateyMat, unsigned int *rearweightMat, unsigned int *leftcoordinatexMat, unsigned int *leftcoordinateyMat, unsigned int *leftweightMat, 
	unsigned int *rightcoordinatexMat, unsigned int *rightcoordinateyMat, unsigned int *rightweightMat, unsigned char *frontImage,  unsigned char *rearImage,  
	unsigned char *leftImage,  unsigned char *rightImage,  	unsigned char *stitchImage, int yoffset, int length, int dstwidthstep);

/************************************************************************/
/*				���̵߳���(�������㡢������ֵ)									*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/*				int xoffset:				x����ƫ����					*/
/*				int yoffset:				y����ƫ����					*/
/*				int dstwidthstep:			��ʾ����ʾ���Ŀ�			*/
/*				int NX:						ˮƽ���򱻷ֳ�NX����		*/
/*				int NY:						��ֱ���򱻷ֳ�NY����		*/
/************************************************************************/
bool GetStitchImage5(unsigned int *frontcoordinatexMat, unsigned int *frontcoordinateyMat, unsigned int *frontweightMat, unsigned int *rearcoordinatexMat, 
	unsigned int *rearcoordinateyMat, unsigned int *rearweightMat, unsigned int *leftcoordinatexMat, unsigned int *leftcoordinateyMat, unsigned int *leftweightMat, 
	unsigned int *rightcoordinatexMat, unsigned int *rightcoordinateyMat, unsigned int *rightweightMat, unsigned char *frontImage,  unsigned char *rearImage,  
	unsigned char *leftImage,  unsigned char *rightImage,  	unsigned char *stitchImage, int xoffset, int yoffset, int dstwidthstep, int NX, int NY);
/************************************************************************/
/*				��ʼ��ƴ�ӱ�(�������㡢������ֵ������Դͼ����������     */
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/************************************************************************/
bool InitStitchMap3(unsigned int **frontcoordinatex, unsigned int **frontcoordinatey, unsigned int **frontweight, unsigned int **rearcoordinatex, 
	unsigned int **rearcoordinatey, unsigned int **rearweight, unsigned int **leftcoordinatex, unsigned int **leftcoordinatey, unsigned int **leftweight, 
	unsigned int **rightcoordinatex, unsigned int **rightcoordinatey, unsigned int **rightweight);
/************************************************************************/
/*				��ʼ��ƴ�ӱ�(�������㡢������ֵ������Դͼ����������ˮƽ���� */
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/************************************************************************/
bool InitStitchMap4(unsigned int **frontcoordinatex, unsigned int **frontcoordinatey, unsigned int **frontweight, unsigned int **rearcoordinatex, 
	unsigned int **rearcoordinatey, unsigned int **rearweight, unsigned int **leftcoordinatex, unsigned int **leftcoordinatey, unsigned int **leftweight, 
	unsigned int **rightcoordinatex, unsigned int **rightcoordinatey, unsigned int **rightweight);
/************************************************************************/
/*				���̵߳���(�������㡢������ֵ������Դͼ��������)		*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/*				int xoffset:				x����ƫ����					*/
/*				int yoffset:				y����ƫ����					*/
/*				int dstwidthstep:			��ʾ����ʾ���Ŀ�			*/
/*				int NX:						ˮƽ���򱻷ֳ�NX����		*/
/*				int NY:						��ֱ���򱻷ֳ�NY����		*/
/************************************************************************/
bool GetStitchImage6(unsigned int *frontcoordinatexMat, unsigned int *frontcoordinateyMat, unsigned int *frontweightMat, unsigned int *rearcoordinatexMat, 
	unsigned int *rearcoordinateyMat, unsigned int *rearweightMat, unsigned int *leftcoordinatexMat, unsigned int *leftcoordinateyMat, unsigned int *leftweightMat, 
	unsigned int *rightcoordinatexMat, unsigned int *rightcoordinateyMat, unsigned int *rightweightMat, unsigned char *srcImage, unsigned char *stitchImage, 
	int xoffset, int yoffset, int dstwidthstep, int NX, int NY);
/************************************************************************/
/*				���̵߳���(�������㡢����Դͼ��������)					*/
/*              ����ȫ��������ȫ��ͼ                                    */
/*				unsigned int *frontcoordinatexMat: ǰ��X�����			*/
/*				unsigned int *frontcoordinateyMat: ǰ��Y�����			*/
/*				unsigned int *frontweightMat:		ǰ��Ȩֵ��			*/
/*				unsigned int *rearcoordinatexMat:	����X�����			*/
/*				unsigned int *rearcoordinateyMat:	����Y�����			*/
/*				unsigned int *rearweightMat:		����Ȩֵ��			*/
/*				unsigned int *leftcoordinatexMat:	����X�����			*/
/*				unsigned int *leftcoordinateyMat:	����Y�����			*/
/*				unsigned int *leftweightMat:		����Ȩֵ��			*/
/*				unsigned int *rightcoordinatexMat: ����X�����			*/
/*				unsigned int *rightcoordinateyMat: ����Y�����			*/
/*				unsigned char *frontImage	ǰ��Դͼ���ڴ��ַ			*/
/*				unsigned char *rearImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *leftImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *rightImage	����Դͼ���ڴ��ַ			*/
/*				unsigned char *stitchImage	���ȫ��ͼ���ڴ��ַ		*/
/*				int xoffset:				x����ƫ����					*/
/*				int yoffset:				y����ƫ����					*/
/*				int dstwidthstep:			��ʾ����ʾ���Ŀ�			*/
/*				int NX:						ˮƽ���򱻷ֳ�NX����		*/
/*				int NY:						��ֱ���򱻷ֳ�NY����		*/
/************************************************************************/
bool GetStitchImage7(unsigned int *frontcoordinatexMat, unsigned int *frontcoordinateyMat, unsigned int *frontweightMat, unsigned int *rearcoordinatexMat, 
	unsigned int *rearcoordinateyMat, unsigned int *rearweightMat, unsigned int *leftcoordinatexMat, unsigned int *leftcoordinateyMat, unsigned int *leftweightMat, 
	unsigned int *rightcoordinatexMat, unsigned int *rightcoordinateyMat, unsigned int *rightweightMat, unsigned char *srcImage, unsigned char *stitchImage, 
	int xoffset, int yoffset, int dstwidthstep, int NX, int NY);

/************************************************************************/
/*				�ں�                                                    */
/************************************************************************/
bool BlendImage(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
/************************************************************************/
/*				��������λ��                                            */
/************************************************************************/
bool GetCarPosition(StitchInfo *front, StitchInfo *rear, StitchInfo *left, StitchInfo *right);
#endif