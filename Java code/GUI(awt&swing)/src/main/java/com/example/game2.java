package com.example;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;

public class game2 {
  private Frame f = new Frame("game2");

  BufferedImage table;
  BufferedImage black;
  BufferedImage white;
  BufferedImage selected;



  final int table_width = 535;
  final int table_height = 536;

  final int Board_size = 15;

  final int Rate = table_width/Board_size;

  final int X_OFFSET = 5;
  final int Y_OFFSET = 6;

  int[][] board = new int [Board_size][Board_size];

  int selectedX = -1;
  int selectedY = -1;

  private class  ChessBoard extends Canvas {
    @Override
    public void paint(Graphics g){

      g.drawImage(table,0,0,null);//画棋盘
      if(selectedX > 0 && selectedY > 0)//画选择框
        g.drawImage(selected,selectedX,selectedY,null);
      for(int i = 0;i<Board_size;i++) {
        for (int j = 0; j < Board_size; j++) {
          if (board[i][j] == 2)//画黑棋
            g.drawImage(black, i * Rate + X_OFFSET, j * Rate + X_OFFSET, null);
          if (board[i][j] == 1)//画白棋
            g.drawImage(white, i * Rate + X_OFFSET, j * Rate + X_OFFSET, null);
        }
      }
    }
  }
  ChessBoard chessBoard = new ChessBoard();

  int board_type = 2;

  Panel p = new Panel();
  Button w = new Button("white");
  Button b = new Button("black");
  Button r = new Button("return");

  public void refreshBtnColor(Color whiteBtnColor,Color blackBtnColor,Color deleteBtnColor){
    w.setBackground(whiteBtnColor);
    b.setBackground(blackBtnColor);
    r.setBackground(deleteBtnColor);
  }

  public void init() throws Exception{
    w.addActionListener(e ->{
      board_type =1;
    });
    b.addActionListener(e ->{
      board_type =2;
    });
    r.addActionListener(e ->{
      board_type=0;
    });
    p.add(w);
    p.add(b);
    p.add(r);
    f.add(p,BorderLayout.SOUTH);

    table = ImageIO.read(new File("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/bg.jpg"));
    white = ImageIO.read(new File("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/hotdog.png"));
    black = ImageIO.read(new File("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/hotdog.png"));
    selected = ImageIO.read(new File("/Users/qianrongsheng/Desktop/Code Mode/Java code/SiCongEatHotDog-master/src/images/sicong.png"));
    //**************************important******************************

    chessBoard.addMouseListener(new MouseAdapter() {
      @Override
      public void mouseMoved(MouseEvent e){
        selectedX = (e.getX()-X_OFFSET)/Rate;
        selectedY = (e.getY()-Y_OFFSET)/Rate;
        chessBoard.repaint();
      }
    });
    chessBoard.addMouseListener(new MouseAdapter() {
      @Override
      public void mouseClicked(MouseEvent e){
        int xPos = (e.getX()-X_OFFSET)/Rate;
        int yPos = (e.getY()-Y_OFFSET)/Rate;

        board[xPos][yPos] = board_type;
        chessBoard.repaint();
      }
      @Override
      public void mouseExited(MouseEvent e){
        selectedX = -1;
        selectedY = -1;

        chessBoard.repaint();
      }
    });

    chessBoard.setPreferredSize(new Dimension(table_width,table_height));
    f.add(chessBoard);
    f.pack();
    f.setVisible(true);
  }
  public static void main(String[] args) throws Exception {
    new game2().init();
  }
}
