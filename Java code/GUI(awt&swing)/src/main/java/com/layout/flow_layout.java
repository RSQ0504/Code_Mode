package com.layout;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class flow_layout {
  public static void main(String[] args){
    Frame frame=new Frame();
    frame.setLayout(new FlowLayout(FlowLayout.LEFT,20,20));
    for (int i=0;i<25;i++)
      frame.add(new Button("1"));

    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame.pack();
    frame.setVisible(true);
  }
}
