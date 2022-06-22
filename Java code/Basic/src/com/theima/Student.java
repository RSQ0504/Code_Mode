package com.theima;
import java.util.Scanner;

public class Student extends Person{
    private String studentid;
    private Student next=null;
    private Course coursehead=null;

    public Student(){
        new Person();
    }
    public Student(String name,int age,String email,String studentid){
        this.setAge(age);
        this.setName(name);
        this.setEmail(email);
        this.studentid=studentid;
    }
    public void setNext(Student next){this.next=next;}
    public Student getNext(){return next;}
    public void setStudentid(String studentid){
        this.studentid=studentid;
    }
    public String getStudentid(){
        return studentid;
    }
    public Course getCoursehead(){
        return coursehead;
    }
    public void setScore(){
        System.out.println("The student name is "+this.getName());
        System.out.println("Do you want to enter a score of a course? Enter the int: 1.yes 2. no");
        int a;
        String course;
        char score;
        Course p1=null;
        Course p2=null;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        while(a==1){
            System.out.println("Enter the name of the course");
            course=sc.next();
            System.out.println("Enter the score of the course");
            score=sc.next().charAt(0);
            if(coursehead==null){
                coursehead=new Course(course,score);
                p2=coursehead;
            }else{
                p1=new Course(course,score);
                p2.setNext(p1);;
                p2=p1;
            }
            System.out.println("Do you want to continue to enter a score of a course? 1.yes 2. no");
            a = sc.nextInt();
        }
        System.out.println();
        return;
    }
    public void printScore(){
        System.out.println("---------------------------------------------------");
        System.out.println("The student name is "+this.getName());
        System.out.println("Age is: "+this.getAge());
        System.out.println("E-mail is: "+this.getEmail());
        System.out.println("ID is: "+this.getStudentid());
        System.out.println("Score:");
        for(Course i=coursehead;i!=null;i=i.getNext()){
            System.out.println("     "+i.getCourse()+"    "+i.getScore());
        }
        System.out.println("---------------------------------------------------");
        System.out.println();
    }
}
