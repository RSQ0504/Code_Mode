package com.theima;
import java.io.File;

public class Course {
    private String course;
    private char score=' ';
    private Course next=null;

    public Course(){
        course=new String();
    }
    public Course(String course,char score){
        this.course=course;
        this.score=score;
    }
    public Course getNext() {
        return next;
    }
    public char getScore() {
        return score;
    }
    public String getCourse() {
        return course;
    }
    public void setCourse(String course) {
        this.course = course;
    }
    public void setNext(Course next) {
        this.next = next;
    }
    public void setScore(char score) {
        this.score = score;
    }
}
