package com.graphic;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class image {
  private Frame frame = new Frame("picture");

  MenuBar menuBar = new MenuBar();
  Menu menu = new Menu("file");
  MenuItem open = new MenuItem("Open");
  MenuItem save = new MenuItem("Save");

  BufferedImage image;

  private class Mycavas extends Canvas{
    @Override
    public void paint(Graphics g){
      g.drawImage(image,0,0,null);
    }
  }
  Mycavas drawArea = new Mycavas();

  public void init(){
    open.addActionListener(e->{
      FileDialog fileDialog = new FileDialog(frame,"open",FileDialog.LOAD);
      fileDialog.setVisible(true);
      String dir = fileDialog.getDirectory();
      String filename = fileDialog.getFile();
      try {
        image = ImageIO.read(new File(dir,filename));
        drawArea.repaint();
      } catch (IOException ex) {
        ex.printStackTrace();
      }
    });
    save.addActionListener(e->{
      FileDialog fileDialog = new FileDialog(frame,"save",FileDialog.SAVE);
      fileDialog.setVisible(true);

      String dir = fileDialog.getDirectory();
      String filename = fileDialog.getFile();

      try {
        ImageIO.write(image,"PNG",new File(dir,filename));
      } catch (IOException ex) {
        ex.printStackTrace();
      }
    });


    menu.add(open);
    menu.add(save);

    menuBar.add(menu);

    frame.setMenuBar(menuBar);
    frame.add(drawArea);

    frame.setBounds(200,200,740,508);
    frame.setVisible(true);
    frame.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
  }
  public static void main(String[] args){
    new image().init();
  }
}
