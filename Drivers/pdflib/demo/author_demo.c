/*
*pdflib测试代码:
*原作者的demo程序
*Created on: 2019-7-9
*Author: jun
*/
#include "demo.h"

#if AUTHOR_DEMO

/*******************************************************************************
 * Code
 ******************************************************************************/
const LPDF_BYTE RAW_IMAGE_DATA[128] = {
    0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xfc,
    0xff, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf0,
    0xf3, 0xf3, 0xff, 0xe0, 0xf3, 0xf3, 0xff, 0xc0,
    0xf3, 0xf3, 0xff, 0x80, 0xf3, 0x33, 0xff, 0x00,
    0xf3, 0x33, 0xfe, 0x00, 0xf3, 0x33, 0xfc, 0x00,
    0xf8, 0x07, 0xf8, 0x00, 0xf8, 0x07, 0xf0, 0x00,
    0xfc, 0xcf, 0xe0, 0x00, 0xfc, 0xcf, 0xc0, 0x00,
    0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x00, 0x00,
    0xff, 0xfe, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00,
    0xff, 0xf8, 0x0f, 0xe0, 0xff, 0xf0, 0x0f, 0xe0,
    0xff, 0xe0, 0x0c, 0x30, 0xff, 0xc0, 0x0c, 0x30,
    0xff, 0x80, 0x0f, 0xe0, 0xff, 0x00, 0x0f, 0xe0,
    0xfe, 0x00, 0x0c, 0x30, 0xfc, 0x00, 0x0c, 0x30,
    0xf8, 0x00, 0x0f, 0xe0, 0xf0, 0x00, 0x0f, 0xe0,
    0xe0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/*
函数功能：创建一个PDF文件了，写入测试数据
输入参数：无
输出参数：无
*/
void author_demo_api(void)
{
	LPDF_Doc pdf;
	LPDF_Page page[2];
	LPDF_Image image;
	LPDF_UINT16 width = 0,height = 0, i = 0;

	pdf = LPDF_New();
	page[0] = LPDF_AddPage(pdf);
	width = LPDF_Page_GetWidth(page[0]);
	height = LPDF_Page_GetHeight(page[0]);
	LPDF_Page_SetRGBFill(page[0], 1.0, 0.0, 0.0);
	LPDF_Page_BeginText(page[0]);
	LPDF_Page_MoveTextPos(page[0], 50, height-20);
	while(font_list[i])
	{
		LPDF_Page_SetFontAndSize(page[0], font_list[i], 24);
		LPDF_Page_ShowText(page[0], "abcdefgABCDEFG12345!\043$\045&+-@?");
		LPDF_Page_MoveTextPos(page[0], 0, -30);
		i++;
	}
	LPDF_Page_SetFontAndSize(page[0],"SimSun",20);
	LPDF_Page_ShowText(page[0], "中文字体");
	LPDF_Page_EndText(page[0]);

	image = LPDF_LoadRawImageFromMem(pdf,RAW_IMAGE_DATA,32,32,LPDF_CS_DEVICE_GRAY,1);
	LPDF_Page_DrawImage(page[0], image, 50, 50, 32, 32);

	LPDF_Page_SaveContext(page[0]);
	page[1] = LPDF_AddPage(pdf);
	LPDF_Page_MoveTo(page[1], width/2-50, height-200);
	LPDF_Page_LineTo(page[1], width/2-50, height-300);
	LPDF_Page_LineTo(page[1], width/2-50+100, height-300);
	LPDF_Page_LineTo(page[1], width/2-50+100, height-200);
	LPDF_Page_LineTo(page[1], width/2-50, height-200);
	LPDF_Page_LineTo(page[1], width/2-50+40, height-140);
	LPDF_Page_LineTo(page[1], width/2-50+40+100, height-140);
	LPDF_Page_LineTo(page[1], width/2-50+100, height-200);
	LPDF_Page_Stroke(page[1]);
	LPDF_Page_MoveTo(page[1], width/2-50+40+100, height-140);
	LPDF_Page_LineTo(page[1], width/2-50+40+100, height-240);
	LPDF_Page_LineTo(page[1], width/2-50+100, height-300);
	LPDF_Page_Stroke(page[1]);
	LPDF_Page_SetLineWidth(page[1],2.5);
	LPDF_Page_MoveTo(page[1],width/2-50,height-300);
	LPDF_Page_LineTo(page[1],width/2-50,height-500);
	LPDF_Page_Stroke(page[1]);
	LPDF_Page_SaveContext(page[1]);
	LPDF_SaveToFile(pdf, "red.pdf");
}

#endif

