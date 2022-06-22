package com.menu;

import java.awt.*;
import java.awt.event.*;

public class basic_menu {
    private Frame frame = new Frame("Test");

    //菜单条
    MenuBar menuBar = new MenuBar();

    //菜单项
    Menu fileMenu = new Menu("file");
    Menu editMenu = new Menu("edit");
    Menu format = new Menu("format");

    //菜单项组件
    MenuItem autoEdit = new MenuItem("autoedit");
    MenuItem copy = new MenuItem("copy");
    MenuItem paste = new MenuItem("paste");
              //设置快捷键
    MenuItem comment = new MenuItem("comment Crtl+Shift+Q",new MenuShortcut(KeyEvent.VK_Q,true));

    TextArea ta = new TextArea(6,40);
    //组装
    public void init(){
      /*
      comment.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          ta.append("点击了注释"+e.getActionCommand());
        }
      });
       */
      //简化：
      comment.addActionListener(e -> ta.append("点击了注释"+e.getActionCommand()));

      format.add(comment);

      editMenu.add(autoEdit);
      editMenu.add(copy);
      editMenu.add(paste);
      editMenu.add(format);

      menuBar.add(fileMenu);
      menuBar.add(editMenu);

      //传入菜单条
      frame.setMenuBar(menuBar);

      frame.add(ta);

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
      new basic_menu().init();
  }
}
