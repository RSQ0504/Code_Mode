package com.listener;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class EventListener {
  Frame frame = new Frame("Listener");
  TextField tf = new TextField(30);
  //事件源
  Button ok = new Button("ok");

  public void init(){
    //监听器
    MyListener myListener = new MyListener();
    //注册监听
    ok.addActionListener(myListener);
    frame.add(tf,BorderLayout.NORTH);
    frame.add(ok,BorderLayout.SOUTH);

    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame.pack();
    frame.setVisible(true);
  }

  private class MyListener implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e){
      tf.setText("Hello");
    }
  }

  public static void main(String[] args){
   new EventListener().init();
  }
}
