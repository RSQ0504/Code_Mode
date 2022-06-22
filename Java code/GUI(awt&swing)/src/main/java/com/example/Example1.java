package com.example;
import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Example1 {

  Frame frame = new Frame();
  TextField tf = new TextField(20);
  TextArea ta = new TextArea(5,20);
  Choice colorchooser = new Choice();
  CheckboxGroup cbg = new CheckboxGroup();
  Checkbox male = new Checkbox("male",true);
  Checkbox female = new Checkbox("female",true);
  Checkbox check = new Checkbox("is married?",true);
  List colorlist = new List(6,true);
  Button ok = new Button("ok");

  public void init(){
    //界面
    //底部
    Box bbox = Box.createHorizontalBox();
    bbox.add(tf);
    bbox.add(ok);
    frame.add(bbox,BorderLayout.SOUTH);

    //选择部分
    colorchooser.add("red");
    colorchooser.add("blue");
    colorchooser.add("yellow");

    Box cbox = Box.createHorizontalBox();
    cbox.add(colorchooser);
    cbox.add(male);
    cbox.add(female);
    cbox.add(check);

    //左上部分
    Box topleft = Box.createVerticalBox();
    topleft.add(ta);
    topleft.add(cbox);

    //右上部分
    colorlist.add("red");
    colorlist.add("blue");
    colorlist.add("yellow");

    //上部合并
    Box top = Box.createHorizontalBox();
    top.add(topleft);
    top.add(colorlist);

    frame.add(top);

    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame.pack();
    frame.setVisible(true);
  }
  public static void main(String[] args){
    new Example1().init();
  }
}
