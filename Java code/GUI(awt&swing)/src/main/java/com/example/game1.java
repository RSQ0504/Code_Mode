package com.example;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import static java.awt.Font.BOLD;

public class game1 {
  private Frame frame = new Frame("game1");

  private final int TABLE_WIDTH = 300;
  private final int TABLE_HEIGHT = 400;

  private final int RACKET_WiDTH = 60;
  private final int RACKET_HEIGHT = 20;

  private final int BALL_SIZE = 16;

  private int ballX = 120;
  private int ballY = 20;
  private int RACKETX =120;
  private final int RACKETY = 340;

  private int ball_speedY = 10;
  private int ball_speedX = 5;

  private boolean isOver = false;

  private Timer timer;

  private class MyCanvas extends Canvas{
    @Override
    public void paint(Graphics g){
      if(isOver){
        g.setColor(Color.BLUE);
        g.setFont(new Font("Times",BOLD,30));
        g.drawString("Game Over",50,200);
      }else{
        //ball
        g.setColor(Color.RED);
        g.fillOval(ballX,ballY,BALL_SIZE,BALL_SIZE);

        //racket
        g.setColor(Color.PINK);
        g.fillRect(RACKETX,RACKETY,RACKET_WiDTH,RACKET_HEIGHT);
      }
    }
  }

  MyCanvas drawArea = new MyCanvas();

  public void init() {
    KeyListener listener = new KeyAdapter() {
      @Override
      public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();
        if (keyCode == KeyEvent.VK_LEFT){
          if(RACKETX > 0)
            RACKETX -= 10;
        }
        if (keyCode == KeyEvent.VK_RIGHT){
          if(RACKETX < TABLE_WIDTH-RACKET_WiDTH)
            RACKETX += 10;
        }
      }
    };
    frame.addKeyListener(listener);
    drawArea.addKeyListener(listener);

    /*
    ActionListener task = new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e){
        if(ballX <= 0 || ballX >= (TABLE_WIDTH-BALL_SIZE))
          ball_speedX = - ball_speedX;

        if(ballY <= 0 || (ballY > RACKETY - BALL_SIZE && ballX > RACKETX && ballX < RACKETX + RACKET_WiDTH))
          ball_speedY = -ball_speedY;

        if (ballY > RACKETY - BALL_SIZE && (ballX < RACKETX || ballX > RACKETX+RACKET_WiDTH)){
          timer.stop();
          isOver = true;
        }
        ballX += ball_speedX;
        ballY += ball_speedY;
        drawArea.repaint();
      }
    };
     */
    ActionListener task = e -> {
      if(ballX <= 0 || ballX >= (TABLE_WIDTH-BALL_SIZE))
        ball_speedX = - ball_speedX;

      if(ballY <= 0 || (ballY > RACKETY - BALL_SIZE && ballX > RACKETX && ballX < RACKETX + RACKET_WiDTH))
        ball_speedY = -ball_speedY;

      if (ballY > RACKETY - BALL_SIZE && (ballX < RACKETX || ballX > RACKETX+RACKET_WiDTH)){
        timer.stop();
        isOver = true;
      }
      ballX += ball_speedX;
      ballY += ball_speedY;
      drawArea.repaint();
    };
    timer = new Timer(100,task);
    timer.start();

    drawArea.setPreferredSize(new Dimension(TABLE_WIDTH,TABLE_HEIGHT));
    frame.add(drawArea);

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
    new game1().init();
}
}
