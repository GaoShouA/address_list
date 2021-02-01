package address_list;

import java.util.Scanner;
/*
 * 版本 v0.1版本
 * 说明只用到了java语言的封装思想，其余两大特征还没有用到
 * 日期:
 * */
class coust{
	private static coust ob1 = new coust();//单例模式
	private static int numcoust;//记录当前用户的数量
	public static String[] strdata = new String[1000];//用户最终存放数据的buffer
	private coust() {}//
	public static coust getcoustClass() {
		return ob1;
	}
	//function 使得 numcoust的值+1
	public static void setaddnumcoust() {
		numcoust++;
	}
	//获取 numcoust 的值
	public static int getnumcoust() {
		return numcoust;
	}
		
}

class Linkman{
	private String name;
	private String age;
	private String sex;
	private String phone;	
	
	public void setlinkman(String name,String age,String sex,String phone) {
		this.name = name;
		this.age = age;
		this.sex = sex;
		this.phone = phone;
	}	
	@Override
	public String toString() {
		return "Linkman [name=" + name + ", age=" + age + ", sex=" + sex + ", phone=" + phone + "]";
	}
	//将数据保存到 strdata
	public static void addDateArrbuffer(Linkman AL_object) {
		int numcou =coust.getnumcoust();
		for(int i=0;i<numcou;i++) {//这里写的非常low,还没优化啊哈
			coust.strdata[i] = AL_object.name+"	"+ AL_object.age+"	"+ AL_object.sex+"	"+ AL_object.phone+"	";
		}
	}	
	//显示所有用户
	public static void Showuser() {
		int numcou =coust.getnumcoust();
		for(int i = 0;i<numcou;i++) {
			System.out.println(coust.strdata[i]);
		}
	}
	
}

public class Addreslist {
	public static void main(String[] args) {
		// TODO Auto-generated method stub;
		//异常还没有学
		try (Scanner sc = new Scanner(System.in)) {
			do {
				//提示信息
				Hint();
				String name = sc.nextLine();
				switch (name) {
				case "1":
					Addresslist();
					break;
				case "2":
					Deluser();
//					System.out.println(getnumcoust());//获取计数测试成功
					break;
				case "3":
					Linkman.Showuser();
					break;
				case "4":
					System.out.println("退出成功！");
					return;
					
				default:
					System.out.println("请输入正确的指令");
					break;
				}		
			}while(true);
		}
		
	}	
	//提示功能表
	private static void Hint() {
		System.out.println("------------通讯录--------------------");
		System.out.println("1,添加用户       		2，删除用户");
		System.out.println("3,显示所有用户  		4，退出");
		System.out.print("请输入:");
	}
	
	//添加联系人
	private static void Addresslist() {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入姓名：");
		String name = sc.nextLine();
		System.out.print("请输入年龄：");
		String age = sc.nextLine();
		System.out.print("请输入性别:");
		String sex = sc.nextLine();
		System.out.print("请输入电话:");
		String phone = sc.nextLine();
		coust.setaddnumcoust();//计数 >>>当前用户数量	
		
		//将数据写入一个数组中存起来？
		Linkman ob1 = new Linkman();
		ob1.setlinkman(name, age, sex,phone);
		Linkman.addDateArrbuffer(ob1);
	}
	//删除用户
	private static void Deluser() {
		//懒
	}
	
	//测试类，获取ob1对象的coust值
	private static int getnumcoust() {
		int numcoust = coust.getnumcoust();
		return numcoust;
	}//实验结果成功
	
}
