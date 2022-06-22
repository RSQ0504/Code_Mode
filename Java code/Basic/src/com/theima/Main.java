package com.theima;

import java.io.File;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.Scanner;

public class Main {
    public static void Output_Student(Student student_head) throws IOException {
        Student p1=student_head;
        Course c1;
        File student =new File("/Users/qianrongsheng/Desktop/CMPT 276-D100/276assignments/Assignment 1/Student.json");
        student.createNewFile();
        FileOutputStream out =new FileOutputStream(student);
        byte[] name;
        byte[] age;
        byte[] email;
        byte[] ID;
        byte[] score;
        byte[] title;
        String Age;
        String Score;
        String newline = "\n";
        byte[] Newline = newline.getBytes();
        while(p1!=null){
            Age=String.valueOf(p1.getAge());
            name=p1.getName().getBytes();
            age=Age.getBytes();
            email=p1.getEmail().getBytes();
            ID=p1.getStudentid().getBytes();
            title="Name: ".getBytes();
            out.write(title);
            out.write(name);
            out.write(Newline);
            title="Age: ".getBytes();
            out.write(title);
            out.write(age);
            out.write(Newline);
            title="Email: ".getBytes();
            out.write(title);
            out.write(email);
            out.write(Newline);
            title="ID: ".getBytes();
            out.write(title);
            out.write(ID);
            out.write(Newline);
            c1=p1.getCoursehead();
            title="Score: ".getBytes();
            out.write(title);
            while(c1!=null){
                Score = c1.getCourse()+"   "+c1.getScore();
                score=Score.getBytes();
                out.write(score);
                out.write(Newline);
                c1=c1.getNext();
            }
            p1=p1.getNext();
        }
        out.close();
    }
    public static void Output_Instructor(Instructor instructor_head) throws IOException {
        Instructor p1=instructor_head;
        Course c1;
        File Instructor =new File("/Users/qianrongsheng/Desktop/CMPT 276-D100/276assignments/Assignment 1/Instructor.json");
        Instructor.createNewFile();
        FileOutputStream out = new FileOutputStream(Instructor);
        byte[] name;
        byte[] age;
        byte[] email;
        byte[] ID;
        byte[] course;
        byte[] title;
        String Age;
        String Course;
        String newline = "\n";
        byte[] Newline = newline.getBytes();
        while(p1!=null){
            Age=String.valueOf(p1.getAge());
            name=p1.getName().getBytes();
            age=Age.getBytes();
            email=p1.getEmail().getBytes();
            ID=p1.getInstructorid().getBytes();
            title="Name: ".getBytes();
            out.write(title);
            out.write(name);
            out.write(Newline);
            title="Age: ".getBytes();
            out.write(title);
            out.write(age);
            out.write(Newline);
            title="Email: ".getBytes();
            out.write(title);
            out.write(email);
            out.write(Newline);
            title="ID: ".getBytes();
            out.write(title);
            out.write(ID);
            out.write(Newline);
            c1=p1.getCoursehead();
            title="Course: ".getBytes();
            out.write(title);
            while(c1!=null){
                Course = c1.getCourse();
                course=Course.getBytes();
                out.write(course);
                out.write(Newline);
                c1=c1.getNext();
            }
            p1=p1.getNext();
        }
        out.close();
    }
    public static Student AddStudent(Student student_head){
        Student p1=student_head;
        Student p2=null;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name:");
        String name = sc.next();
        System.out.println("Enter the age: ");
        int age = sc.nextInt();
        System.out.println("Enter the email: ");
        String email =sc.next();
        System.out.println("Enter the ID: ");
        String id =sc.next();
        if(student_head==null){
            student_head=new Student(name,age,email,id);
            student_head.setScore();
            p1=student_head;
        }else{
            while(p1.getNext()!=null)
                p1=p1.getNext();
            p2=new Student(name,age,email,id);
            p2.setScore();
            p1.setNext(p2);
            p1=p2;
        }
        System.out.println("Do you want to continue to add student? Enter the int: 1.yes 2. no");
        int a;
        a=sc.nextInt();
        while(a==1){
            System.out.println("Enter the name:");
            name=sc.next();
            System.out.println("Enter the age: ");
            age = sc.nextInt();
            System.out.println("Enter the email: ");
            email =sc.next();
            System.out.println("Enter the ID: ");
            id =sc.next();
            p2=new Student(name,age,email,id);
            p2.setScore();
            p1.setNext(p2);
            p1=p2;
            System.out.println("Do you want to continue to add student? Enter the int: 1.yes 2. no");
            a=sc.nextInt();
        }
        return student_head;
    }
    public static  Instructor AddInstructor(Instructor instructor_head){
        Instructor p1=instructor_head;
        Instructor p2=null;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the name:");
        String name = sc.next();
        System.out.println("Enter the age: ");
        int age = sc.nextInt();
        System.out.println("Enter the email: ");
        String email =sc.next();
        System.out.println("Enter the ID: ");
        String id =sc.next();
        if(instructor_head==null){
            instructor_head=new Instructor(name,age,email,id);
            instructor_head.setTeaching();
            p1=instructor_head;
        }else{
            while(p1.getNext()!=null)
                p1=p1.getNext();
            p2=new Instructor(name,age,email,id);
            p2.setTeaching();
            p1.setNext(p2);
            p1=p2;
        }
        System.out.println("Do you want to continue to add an instructor? Enter the int: 1.yes 2. no");
        int a;
        a=sc.nextInt();
        while(a==1){
            System.out.println("Enter the name:");
            name=sc.next();
            System.out.println("Enter the age: ");
            age = sc.nextInt();
            System.out.println("Enter the email: ");
            email =sc.next();
            System.out.println("Enter the ID: ");
            id =sc.next();
            p2=new Instructor(name,age,email,id);
            p2.setTeaching();
            p1.setNext(p2);
            p1=p2;
            System.out.println("Do you want to continue to add an instructor? Enter the int: 1.yes 2. no");
            a=sc.nextInt();
        }
        return instructor_head;
    }
    public static  void main(String[] arge) throws IOException {
        int check,choose;
        Student student_head=null;
        Instructor instructor_head=null;
        System.out.println("Do you want to add a person? 1.Yes   2.No");
        Scanner sc = new Scanner(System.in);
        check = sc.nextInt();
        while(check==1){
            System.out.println("Student or Instructor?");
            System.out.println("1. Student   2.Instructor");
            choose=sc.nextInt();
            switch (choose){
                case 1 : if(student_head==null) {student_head=AddStudent(student_head);
                } else {AddStudent(student_head);}
                    break;
                case 2 : if(instructor_head==null){instructor_head=AddInstructor(instructor_head);
                }else{AddInstructor(instructor_head);}
                    break;
                default: System.out.println("Wrong input");break;
            }
            System.out.println("Do you want to continue to add a person? 1.Yes   2.No");
            check = sc.nextInt();
        }
        Output_Student(student_head);
        Output_Instructor(instructor_head);
        System.out.println("Student Information");
        Student p1=student_head;
        Instructor p2=instructor_head;
        while(p1!=null){
            p1.printScore();
            p1=p1.getNext();
        }
        System.out.println("Instructor Information");
        while(p2!=null){
            p2.printTeaching();
            p2=p2.getNext();
        }
    }
}
