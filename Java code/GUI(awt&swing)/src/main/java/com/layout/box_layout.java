package com.layout;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class box_layout {
  public static void main(String[] args){

    //*************************************************Boxlayout*****************************************************
    Frame frame4 = new Frame("Boxlayout");
    //frame4.setLayout(new BoxLayout(frame4,BoxLayout.Y_AXIS));
    //frame4.add(new Button("1"));
    //frame4.add(new Button("2"));
    Box hbox = Box.createHorizontalBox();
    hbox.add(new Button("1"));
    hbox.add(Box.createHorizontalGlue());
    hbox.add(new Button("2"));
    hbox.add(Box.createHorizontalStrut(20));
    hbox.add(new Button("3"));

    Box vbox = Box.createVerticalBox();
    vbox.add(new Button("1"));
    vbox.add(Box.createVerticalGlue());
    vbox.add(new Button("2"));
    vbox.add(Box.createVerticalStrut(20));
    vbox.add(new Button("3"));

    frame4.add(hbox,BorderLayout.NORTH);
    frame4.add(vbox,BorderLayout.SOUTH);

    frame4.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame4.pack();
    frame4.setVisible(true);
  }
}
