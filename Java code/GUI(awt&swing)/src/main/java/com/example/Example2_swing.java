package com.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Example2_swing {
  JFrame f = new JFrame("Teset swing");

  JMenuBar menuBar = new JMenuBar();

  JMenu fileMenu = new JMenu("file");
  JMenu editMenu = new JMenu("edit");

  JMenuItem auto = new JMenuItem("auto",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));
  JMenuItem copy = new JMenuItem("copy",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));
  JMenuItem paste = new JMenuItem("paste",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));

  JMenu formatMenu = new JMenu("format");
  JMenuItem comment= new JMenuItem("comment",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));
  JMenuItem cancel = new JMenuItem("cancel",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));

  JTextArea ta = new JTextArea(8,20);

  String[] colors = {"red","green","blue"};//******************************
  JList<String> colorlist = new JList<String>(colors);
  JComboBox<String> colorselect = new JComboBox<String>();

  ButtonGroup bg = new ButtonGroup();//************************************
  JRadioButton male = new JRadioButton("male",false);
  JRadioButton female = new JRadioButton("female",false);

  JCheckBox isMarried = new JCheckBox("married?",true);

  JTextField tf = new JTextField(40);
  JButton ok = new JButton("OK",new ImageIcon("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));

  JPopupMenu jPopupMenu = new JPopupMenu();

  ButtonGroup popupButtonbg = new ButtonGroup();//***********************

  JRadioButtonMenuItem metal = new JRadioButtonMenuItem("metal");
  JRadioButtonMenuItem nimbus = new JRadioButtonMenuItem("nimbus");
  JRadioButtonMenuItem windows = new JRadioButtonMenuItem("windows");
  JRadioButtonMenuItem motify = new JRadioButtonMenuItem("motify");

  public void init(){
    JPanel bottom = new JPanel();
    bottom.add(tf);
    bottom.add(ok);

    f.add(bottom, BorderLayout.SOUTH);

    JPanel select = new JPanel();

    colorselect.addItem("red");
    colorselect.addItem("green");
    colorselect.addItem("blue");

    select.add(colorselect);
    bg.add(male);
    bg.add(female);
    select.add(male);
    select.add(female);
    select.add(isMarried);

    Box topLeft = Box.createVerticalBox();
    topLeft.add(ta);
    topLeft.add(select);

    Box top = Box.createHorizontalBox();
    //colorlist.add();
    top.add(topLeft);
    top.add(colorlist);

    f.add(top);

    formatMenu.add(comment);
    formatMenu.add(cancel);

    editMenu.add(auto);
    editMenu.addSeparator();
    editMenu.add(copy);
    editMenu.add(paste);
    editMenu.addSeparator();
    editMenu.add(formatMenu);

    menuBar.add(fileMenu);
    menuBar.add(editMenu);

    f.setJMenuBar(menuBar);

    popupButtonbg.add(metal);
    popupButtonbg.add(nimbus);
    popupButtonbg.add(windows);
    popupButtonbg.add(motify);

    ActionListener listener = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e){
        String action = e.getActionCommand();
        try {
          change(action);
        } catch (Exception ex) {
          ex.printStackTrace();
        }
      }
    };
    metal.addActionListener(listener);
    nimbus.addActionListener(listener);
    windows.addActionListener(listener);
    motify.addActionListener(listener);

    jPopupMenu.add(metal);
    jPopupMenu.add(nimbus);
    jPopupMenu.add(windows);
    jPopupMenu.add(motify);

    ta.setComponentPopupMenu(jPopupMenu);

    //****************************************************
    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//***************************
    f.pack();
    f.setVisible(true);
  }

  private void change(String action)throws Exception {
    switch (action){
      case "metal":
        UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
        break;
      case "nimbus":
        UIManager.setLookAndFeel("javax.swing.plaf.nimbus.NimbusLookAndFeel");
        break;
      case "windows":
        UIManager.setLookAndFeel("com.sun.java.swing.plaf.Windows.WindowsLookAndFeel");
        break;
      case "motify":
        UIManager.setLookAndFeel("com.sun.java.swing.plaf.motify.MotifyLookAndFeel");
        break;
    }
    //刷新组件外观：*************************************
    SwingUtilities.updateComponentTreeUI(f);
    SwingUtilities.updateComponentTreeUI(menuBar);
    SwingUtilities.updateComponentTreeUI(jPopupMenu);
  }
  public static void main(String[] args){
    new Example2_swing().init();
  }
}
