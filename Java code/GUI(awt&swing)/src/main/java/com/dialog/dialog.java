package com.dialog;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class dialog {
  public static void main(String[] args){
    Frame frame = new Frame("Dialog");
    Dialog d1 = new Dialog(frame,"1");
    Dialog d2 = new Dialog(frame, "2");
    FileDialog d3 = new FileDialog(frame,"保存文件",FileDialog.SAVE);
    FileDialog d4 = new FileDialog(frame,"打开文件",FileDialog.LOAD);

    d1.add(new TextField("你好"));
    d2.add(new TextField("你坏"));
    d1.setBounds(20,30,200,300);
    d2.setBounds(20,30,200,300);

    Button b1 = new Button("b1");
    Button b2 = new Button("b2");
    Button b3 = new Button("save");
    Button b4 = new Button("open");

    /*
    b1.addActionListener(new ActionListener(){
      @Override
      public void actionPerformed(ActionEvent e) {
        d1.setVisible(true);
      }
    });
    b2.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        d2.setVisible(true);
      }
    });
    b3.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        d3.setVisible(true);

        String directory = d3.getDirectory();
        String file = d3.getFile();
        System.out.println("path"+directory+"        name"+file);
      }
    });
    b4.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        d4.setVisible(true);

        String directory = d3.getDirectory();
        String file = d3.getFile();
        System.out.println("path"+directory+"        name"+file);
      }
    });
     */
    //简化：
    b1.addActionListener(e -> d1.setVisible(true));
    //简化：
    b2.addActionListener(e -> d2.setVisible(true));
    //简化：
    b3.addActionListener(e -> {
      d3.setVisible(true);
      String directory = d3.getDirectory();
      String file = d3.getFile();
      System.out.println("path"+directory+"        name"+file);
    });
    //简化：
    b4.addActionListener(e -> {
      d4.setVisible(true);
      String directory = d3.getDirectory();
      String file = d3.getFile();
      System.out.println("path"+directory+"        name"+file);
    });

    frame.add(b1,BorderLayout.NORTH);
    frame.add(b2,BorderLayout.SOUTH);
    Box c = Box.createVerticalBox();
    c.add(b3);
    c.add(b4);
    frame.add(c);

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
