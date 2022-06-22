package com.graphic;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class graphic {
  private final String RECT = "rect";
  private final String OVAL = "oval";

  private Frame frame = new Frame("draw");
  Button b1 = new Button("RECT");
  Button b2 = new Button("OVAL");

  //设置变量，记录要画的形状
  private String shape = "";

  //自定义类，继承Canvas类，重写paint(Graphic g)方法完成画图
  private class MyCanvas extends Canvas {
    @Override
    public void paint(Graphics g) {
      if (shape.equals(RECT)) {
        g.setColor(Color.RED);
        g.drawRect(100, 100, 150, 100);
      } else if (shape.equals(OVAL)) {
        g.setColor(Color.BLACK);
        g.drawOval(100, 100, 150, 100);
      }
    }
  };
  MyCanvas drawCanvas = new MyCanvas();

  public void init(){
    /*
    b1.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e){
        shape = RECT;
        drawCanvas.repaint();//重绘：删除原来的画，再来paint
      }
    });
     */

    //简化：
    b1.addActionListener(e -> {
      shape = RECT;
      drawCanvas.repaint();//重绘：删除原来的画，再来paint
    });
    /*
    b2.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e){
        shape = OVAL;
        drawCanvas.repaint();//重绘：删除原来的画，再来paint
      }
    });
     */

    //简化：
    b2.addActionListener(e -> {
      shape = OVAL;
      drawCanvas.repaint();//重绘：删除原来的画，再来paint
    });

    Panel p = new Panel();
    p.add(b1);
    p.add(b2);
    frame.add(p,BorderLayout.SOUTH);

    drawCanvas.setPreferredSize(new Dimension(300,300));
    frame.add(drawCanvas);

    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame.pack();
    frame.setVisible(true);
  }
  public static void main(String[] ars){
    new graphic().init();
  }
}
