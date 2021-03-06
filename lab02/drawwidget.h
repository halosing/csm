##ifndef DRAWWIDGET_H
#define DRAWWIDGET_H
#include <common.h>
#include <QWidget>
#include <QPixmap>
#include <QPoint>
#include <QPainter>
#include <QPalette>


class DrawWidget : public QWidget   //绘图区窗口类 本类作为绘图的核心对象之一，负责处理用户的绘图操作、画板对象的管理等工作。 绘图操作的核心是内容是实现包括鼠标按下、鼠标移动和鼠标释放的鼠标事件的处理。 画板的管理以画板清除、画板尺寸管理等功能为主，关键在于处理resizeEvent和 paintEvent

{
   Q_OBJECT
public:
   explicit DrawWidget(QWidget *parent = 0);
   ~DrawWidget();

   void setShapeType(ST::ShapeType type);
   ST::ShapeType shapeType();
   void setDrawnText(QString text);
   void pict();

protected:
   void mousePressEvent (QMouseEvent *e);
   void mouseMoveEvent (QMouseEvent *e);
   void mouseReleaseEvent(QMouseEvent *e);
   void paintEvent (QPaintEvent *);
   void resizeEvent (QResizeEvent *);

   void drawShape(const QPointF ptStart,const QPointF ptEnd,const ST::ShapeType drawType);//根据起始点、结束点和绘图类型进行绘图
   QRectF textRect(const QPointF ptStart, const QPointF ptEnd, QString displayText, QFontMetrics fm);

signals:
public slots:
   void setStyle(int);//接收用户选定的画笔风格
   void setWidth(int);//接收用户选定的画笔宽度值
   void setColor(QColor);//接收用户选定的画笔颜色值
   //void pict();//该函数添加需要的图片

   void clear();//清除函数只需调用一个新的、干净的QPixmap对象代替pix，并调用update()重绘即可

private :
   QPixmap *pix;
   QPixmap *pia;
   QPoint startpos;
   QPoint endpos;
   bool canDraw;
   int style;
   int weight;
   QColor color;
  ST::ShapeType drawType;
   QString drawnText;
   QString filename;


};
#endif // DRAWWIDGET_H





































































































































































































































































































