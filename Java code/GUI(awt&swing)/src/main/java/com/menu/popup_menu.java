package com.menu;

import java.awt.*;
import java.awt.event.*;

public class popup_menu {
  private Frame frame = new Frame("popupmenu");
  TextArea ta = new TextArea("hello",6 ,40);
  Panel p = new Panel();

  //popupmenu
  PopupMenu popup = new PopupMenu();

  MenuItem autoEdit = new MenuItem("autoedit");
  MenuItem copy = new MenuItem("copy");
  MenuItem paste = new MenuItem("paste");
  //设置快捷键
  MenuItem comment = new MenuItem("comment Crtl+Shift+Q",new MenuShortcut(KeyEvent.VK_Q,true));

  public void init(){

    popup.add(autoEdit);
    popup.add(paste);
    popup.add(copy);
    popup.add(comment);

    /*
    ActionListener listener = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        ta.append("点击了"+e.getActionCommand()+"\n");
      }
    };
     */

    //简化：
    ActionListener listener = e -> ta.append("点击了"+e.getActionCommand()+"\n");
    comment.addActionListener(listener);
    autoEdit.addActionListener(listener);
    paste.addActionListener(listener);
    copy.addActionListener(listener);


    //加入popupmenu
    p.add(popup);

    //设置panel大小
    p.setPreferredSize(new Dimension(400,300));

    //注册鼠标事件
    p.addMouseListener(new MouseAdapter(){
      @Override
      public void mouseReleased(MouseEvent e){
        boolean flag = e.isPopupTrigger();
        if(flag) {
          //显示popup
          popup.show(p, e.getX(), e.getY());
        }
      }
    });

    frame.add(ta);
    frame.add(p,BorderLayout.SOUTH);

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
    new popup_menu().init();
  }
}
