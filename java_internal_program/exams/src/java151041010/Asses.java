package java151041010;

import java.util.Scanner;

public class Asses {

	public static void main(String[] args) {

		DBHandler DBh = new DBHandler();
		String username = "arjun";

		Scanner sc = new Scanner(System.in);
		int option;
		int flag=1;
		// flag will be set to 0 when exit  
		while (flag == 1){
			System.out.println("options : \n(1) Enter a text(db & File) \n(2) Read From Table \n(3) Read From File \n(4) Exit ");
			try{
				option = sc.nextInt();
			}catch(Exception e){
				// for invalid options 
				option = 99;
				sc = new Scanner(System.in);
			}
			switch(option){
				case 1: System.out.println("Enter the text to write");
						String txt = sc.next();
						// insert to file and db
						DBh.insertTable("assestemp", txt);
						DBh.insertFile(username,txt);
						break;
						
						// read from a table
				case 2: System.out.println("Reading from Database");
						DBh.getResult("assestemp");
						break;
						
						// from a file
				case 3: System.out.println("Read From File");
						DBh.readFileToConsole(username+"_txt.txt");
						break;

						// exit
				case 4: System.out.println("Good Bye..");
						sc.close();
						flag=0; // break loop
						return;
						//break;
				
				default : System.out.println("Invalid option Entered");
						break;
			}
		}
	}

}