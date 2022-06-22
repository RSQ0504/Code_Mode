package com.layout;

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;

public class bord_swing {
  JFrame jf = new JFrame("bord");
  public  void init() {
    jf.setLayout(new GridLayout(2, 4));

    Border bevelBorder = BorderFactory.createBevelBorder(BevelBorder.RAISED,Color.RED,Color.GREEN,Color.BLUE,Color.GRAY);
    jf.add(getJPanelwithBorder(bevelBorder,"BevelBorder"));

    Border lineBorder = BorderFactory.createLineBorder(Color.ORANGE,10);
    jf.add(getJPanelwithBorder(lineBorder,"LineBorder"));

    Border emptyBorder = BorderFactory.createEmptyBorder(10,5,20,10);
    jf.add(getJPanelwithBorder(emptyBorder,"emptyBorder"));

    Border echtedBorder = BorderFactory.createEtchedBorder(EtchedBorder.RAISED,Color.RED,Color.GREEN);
    jf.add(getJPanelwithBorder(echtedBorder,"ehtedBorder"));

    TitledBorder title = new TitledBorder(new LineBorder(Color.ORANGE,10),"test");
    jf.add(getJPanelwithBorder(title,"titleBorder"));

    MatteBorder matteBorder = new MatteBorder(10,5,20,10,Color.GREEN);
    jf.add(getJPanelwithBorder(matteBorder,"matteBorder"));

    CompoundBorder compound = new CompoundBorder(title,new LineBorder(Color.RED,10));
    jf.add(getJPanelwithBorder(compound,"compound"));

    jf.pack();
    jf.setVisible(true);
    jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  public JPanel getJPanelwithBorder(Border border,String content){
    JPanel jp = new JPanel();
    jp.add(new JLabel(content));

    jp.setBorder(border);
    return jp;
  }
  public static void main(String[] args){
    new bord_swing().init();
  }
}
