package address_list;

import java.util.Scanner;
/*
 * �汾 v0.1�汾
 * ˵��ֻ�õ���java���Եķ�װ˼�룬��������������û���õ�
 * ����:
 * */
class coust{
	private static coust ob1 = new coust();//����ģʽ
	private static int numcoust;//��¼��ǰ�û�������
	public static String[] strdata = new String[1000];//�û����մ�����ݵ�buffer
	private coust() {}//
	public static coust getcoustClass() {
		return ob1;
	}
	//function ʹ�� numcoust��ֵ+1
	public static void setaddnumcoust() {
		numcoust++;
	}
	//��ȡ numcoust ��ֵ
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
	//�����ݱ��浽 strdata
	public static void addDateArrbuffer(Linkman AL_object) {
		int numcou =coust.getnumcoust();
		for(int i=0;i<numcou;i++) {//����д�ķǳ�low,��û�Ż�����
			coust.strdata[i] = AL_object.name+"	"+ AL_object.age+"	"+ AL_object.sex+"	"+ AL_object.phone+"	";
		}
	}	
	//��ʾ�����û�
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
		//�쳣��û��ѧ
		try (Scanner sc = new Scanner(System.in)) {
			do {
				//��ʾ��Ϣ
				Hint();
				String name = sc.nextLine();
				switch (name) {
				case "1":
					Addresslist();
					break;
				case "2":
					Deluser();
//					System.out.println(getnumcoust());//��ȡ�������Գɹ�
					break;
				case "3":
					Linkman.Showuser();
					break;
				case "4":
					System.out.println("�˳��ɹ���");
					return;
					
				default:
					System.out.println("��������ȷ��ָ��");
					break;
				}		
			}while(true);
		}
		
	}	
	//��ʾ���ܱ�
	private static void Hint() {
		System.out.println("------------ͨѶ¼--------------------");
		System.out.println("1,����û�       		2��ɾ���û�");
		System.out.println("3,��ʾ�����û�  		4���˳�");
		System.out.print("������:");
	}
	
	//�����ϵ��
	private static void Addresslist() {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		System.out.print("������������");
		String name = sc.nextLine();
		System.out.print("���������䣺");
		String age = sc.nextLine();
		System.out.print("�������Ա�:");
		String sex = sc.nextLine();
		System.out.print("������绰:");
		String phone = sc.nextLine();
		coust.setaddnumcoust();//���� >>>��ǰ�û�����	
		
		//������д��һ�������д�������
		Linkman ob1 = new Linkman();
		ob1.setlinkman(name, age, sex,phone);
		Linkman.addDateArrbuffer(ob1);
	}
	//ɾ���û�
	private static void Deluser() {
		//��
	}
	
	//�����࣬��ȡob1�����coustֵ
	private static int getnumcoust() {
		int numcoust = coust.getnumcoust();
		return numcoust;
	}//ʵ�����ɹ�
	
}
