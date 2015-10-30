
package daycarecenter;
import db.*;
import java.sql.*;
import java.util.Scanner;
import java.util.InputMismatchException;


public class FrontController {


	public static void main(String argv[]){
		Scanner sc = new Scanner(System.in);


		try{
			TableHandler T = new TableHandler();
			InputHandlerTable inpH = new InputHandlerTable();
			int option;
			String value = "";
			int result = 0;
			while(1 == 1){
	 			System.out.print("Options \nDisplay :\n (1) Patient Information  ");
				System.out.print(" (2) allergy Infomation (3) Patient History \n");
				System.out.print("\nInsert :\n (4) Patient_Information (5) allergy Infomation (6) Patient History\n");
				System.out.print("Enter your choice : ");

				try{
					option = sc.nextInt();	
				}
				catch(InputMismatchException e){
					sc = new Scanner(System.in);
					option = 99;
				}
			
				switch (option){
					case 1 : System.out.println("Patient Information"); T.displayTable("patient_details"); break;
					case 2 : System.out.println("allergy Infomation");T.displayTable("allergy_information"); break;
					case 3 : System.out.println("Patient History");T.displayTable("medical_history"); break;
					case 4 : value = inpH.getInput_patient_details();
							 result = T.insertTable("patient_details",value);
							 System.out.format(" %d row updated \n",result);break;
					case 5 : value = inpH.getInput_Allergy_details();
							 result = T.insertTable("allergy_information",value);
							 System.out.format(" %d row updated \n",result);break;
					case 6 : value = inpH.getInput_Medical_details();
							 result = T.insertTable("medical_history",value);
							 System.out.format(" %d row updated \n",result);break;

					case 0 : return ;

					default : System.out.println("Invalid option entered ");

				}
			}
		}
		catch(Exception e){
			System.out.println("error : "+e);

		}
		finally{
			sc.close();
		}

	}
}