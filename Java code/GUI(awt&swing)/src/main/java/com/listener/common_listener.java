package com.listener;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class common_listener {
  public static void main(String[] args) {
    Frame frame = new Frame("listener");

    TextField tf = new TextField(30);
    Choice names = new Choice();
    names.add("束妮");
    names.add("钱荣晟");

    //Textlistener
    /*
    tf.addTextListener(new TextListener() {
      @Override
      public void textValueChanged(TextEvent e){
        String text = tf.getText();
        System.out.println(text);
      }
    });
     */
    //简化：
    tf.addTextListener(e -> {
      String text = tf.getText();
      System.out.println(text);
    });

    //itemlistener
    /*
    names.addItemListener(new ItemListener(){
      @Override
      public void itemStateChanged(ItemEvent e){
        Object item = e.getItem();
        System.out.println(item);
      }
    });
     */
    //简化：
    names.addItemListener(e -> {
      Object item = e.getItem();
      System.out.println(item);
    });

    //Containerlistener
    frame.addContainerListener(new ContainerListener(){
      @Override
      public void componentAdded(ContainerEvent e){
        Component child = e.getChild();
        System.out.println(child);
      }

      @Override
      public void componentRemoved(ContainerEvent e){

      }
    });

    //Windowlistener
    /*
    frame.addWindowListener(new WindowListener(){
      @Override
      public void windowOpened(WindowEvent e) {

      }

      @Override
      public void windowClosing(WindowEvent e) {

      }

      @Override
      public void windowClosed(WindowEvent e) {

      }

      @Override
      public void windowIconified(WindowEvent e) {

      }

      @Override
      public void windowDeiconified(WindowEvent e) {

      }

      @Override
      public void windowActivated(WindowEvent e) {

      }

      @Override
      public void windowDeactivated(WindowEvent e) {

      }
    });
*/ //origin method
    //easy method
    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });

    Box hbox = Box.createHorizontalBox();
    hbox.add(names);
    hbox.add(tf);

    frame.add(hbox);
    frame.pack();
    frame.setVisible(true);

  }
}
