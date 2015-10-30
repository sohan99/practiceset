
package daycarecenter;
import db.*;
import java.sql.*;
import java.util.Scanner;
import java.util.InputMismatchException;

/*
patientid integer NOT NULL,
  name character varying(255),
  address character varying(255),
  email_id character varying(255),
  ph_number character varying(255),
  active integer,
  gender character varying(255),
  */
public class InputHandlerTable {
		Scanner sc;
		public InputHandlerTable(){
			sc = new Scanner(System.in);
		}

		public String getInput_patient_details(){
				int patientId = 0;
				String name = "";
				String address = "";
				String email_id = "";
				int activeState = 0;
				String gender = "";
				String phNo = "";
				int done_flag = 1;
				while(done_flag == 1){
					try{
						System.out.println("Enter Patient Id :");
						patientId = sc.nextInt();

						System.out.println("Enter Patient Name :");
						name = sc.next();

						System.out.println("Enter Patient Address :");
						address = sc.next();

						System.out.println("Enter Patient Email Id :");
						email_id = sc.next();

						System.out.println("Enter Patient Phone Number:");
						phNo = sc.next();

						System.out.println("Enter Patient State (Active/Inactive) :");
						activeState = sc.nextInt();

						System.out.println("Enter Patient gender :");
						gender= sc.next();

						//flag to stop the loop
						done_flag = 0;
					}

					catch(InputMismatchException e){
						System.out.println("There was an error while entering input. Please enter it again\n");
						sc = new Scanner(System.in);
						done_flag = 1;
					}
				}
				String out = ""+Integer.toString(patientId	)+",'"+name+"','"+address+"','"+email_id+"','"+phNo+"',"+Integer.toString(activeState)+",'"+gender+"'";
				return out;
		}
/*
 patientid integer,
  allergyid integer NOT NULL,
  allergy_information character varying(255)


*/
public String getInput_Allergy_details(){
				int patientId = 0;
				int allergyid = 0;
				String allergy_information = "";
				int done_flag = 1;
				while(done_flag == 1){
					try{
						System.out.println("Enter Patient Id :");
						patientId = sc.nextInt();

						System.out.println("Enter Allergy Id :");
						allergyid = sc.nextInt();

						System.out.println("Enter Allergy Information :");
						allergy_information= sc.next();

						//flag to stop the loop
						done_flag = 0;
					}

					catch(InputMismatchException e){
						System.out.println(" there was an error while entering input . please enter it again");
						sc = new Scanner(System.in);
						done_flag = 1;
					}
				}
				String out = ""+Integer.toString(patientId	)+","+Integer.toString(allergyid)+",'"+allergy_information+"'";
				return out;
		}


/*
  patientid integer,
  description character varying(400),
  vaccination character varying(255),

*/


	public String getInput_Medical_details(){
					int patientId = 0;
					String description = "";
					String vaccination = "";
					int done_flag = 1;
					while(done_flag == 1){
						try{
							System.out.println("Enter Patient Id :");
							patientId = sc.nextInt();

							System.out.println("Enter Allergy Id :");
							description = sc.next();

							System.out.println("Enter Vaccination :");
							vaccination= sc.next();

							//flag to stop the loop
							done_flag = 0;
						}

						catch(InputMismatchException e){
							System.out.println(" there was an error while entering input . please enter it again");
							sc = new Scanner(System.in);
							done_flag = 1;
						}
					}
					String out = ""+Integer.toString(patientId	)+",'"+description+"','"+vaccination+"'";
					return out;
			}
	}
