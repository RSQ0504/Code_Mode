package com.layout;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class card_layout {
  public static void main(String[] args) {

    //*************************************************Cardlayout*****************************************************

    Frame frame3 = new Frame("Cardlayout");
    Panel p1 = new Panel();
    CardLayout card = new CardLayout();
    p1.setLayout(card);

    String[] names = {"1", "2", "3", "4", "5"};
    for (int i = 0; i < names.length; i++) {
      p1.add(names[i], new Button(names[i]));
    }
    frame3.add(p1);

    Panel p2 = new Panel();
    Button b1 = new Button("<");
    Button b2 = new Button(">");

    ActionListener listener = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        String action = e.getActionCommand();
        switch (action) {
          case "<":
            card.previous(p1);
            break;
          case ">":
            card.next(p1);
            break;
        }
      }
    };
    b1.addActionListener(listener);
    b2.addActionListener(listener);

    p2.add(b1);
    p2.add(b2);
    frame3.add(p2, BorderLayout.SOUTH);

    frame3.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
    frame3.pack();
    frame3.setVisible(true);
  }
}
