package com.layout;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class broadlayout_gridlayout {
  public static void main(String[] args) {

    //*************************************************计算器(broadlayout & Gridlayout*****************************************************

    Frame frame2 = new Frame("计算器(broadlayout & Gridlayout)");
    //frame2.setLayout(new BorderLayout(30,10));

    //frame2.add(new Button("North"),BorderLayout.NORTH);
    //frame2.add(new Button("Centre"),BorderLayout.CENTER);
    Panel p = new Panel();
    p.add(new TextField(30));
    frame2.add(p, BorderLayout.NORTH);

    Panel p2 = new Panel();
    p.setLayout(new GridLayout(3, 5, 4, 4));
    for (int i = 0; i < 10; i++)
      p2.add(new Button(i + ""));
    frame2.add(p2);

    frame2.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame2.pack();
    frame2.setVisible(true);
  }
}
