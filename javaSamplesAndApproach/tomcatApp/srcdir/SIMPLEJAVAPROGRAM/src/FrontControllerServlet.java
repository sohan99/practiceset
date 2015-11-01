
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Calendar;
import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import javax.servlet.ServletException;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.ServletConfig;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.*;

import java.util.Map;
import org.json.simple.JSONObject;

import db.TableHandler;

public class FrontControllerServlet extends HttpServlet	
{
	//HttpSession session = null;
	private String appdir = null;
	private String strContextPath = null;
	private ServletConfig config = null;

	public void init(ServletConfig paramServletConfig)
	{
		appdir = System.getProperty("catalina.base");
		this.config = paramServletConfig;
            
	}

	/*
	 * This is the doPost method called when the request is of POST method. Automatically called from service method of HttServlet.
	 */
	public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException,ServletException
	{
		doGet(req, res);
	}

	/*
	 * This is the doGet method called when the request is of GET method. Automatically called from service method of HttServlet.
	 */
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException,ServletException
	{
		process(req,res);
	}	

	protected void process(HttpServletRequest req, HttpServletResponse res) throws IOException,ServletException
	{
		//HttpSession session = req.getSession(false);
		System.out.println("#process ==> ");                
		//HttpSession session = req.getSession();
        PrintWriter out = res.getWriter();

		//strContextPath = session.getServletContext().getContextPath();
		String uri = req.getRequestURI();
		System.out.println("uri ================ "+uri);
		res.setContentType("text/html");

		try
		{
		    	//session.setAttribute("DAYCARE", 10);
				JSONObject objJson = new JSONObject();
				TableHandler T1 = new TableHandler();
				String op = "";
				if(uri.endsWith("view_patient_details.do"))
				{	
					System.out.println("hit inside view_patient_details");
					op = T1.displayTable("patient_details");

					out.print(op);
					
				}
				else if(uri.endsWith("allergy_info.do"))
				{	
					System.out.println("hit inside allergy_info");
					op = T1.displayTable("allergy_information");

					out.print(op);
					
				}
				else if(uri.endsWith("medical_history.do"))
				{	
					System.out.println("hit inside medical_history");
					op = T1.displayTable("medical_history");
					out.print(op);
					
				}	//allergy_info
				else if(uri.endsWith("add_patient.do"))
				{	
					String val = req.getParameter("val");
					System.out.println("hit inside addPatient");
					System.out.println(val);
					objJson = T1.insertTable("patient_details",val);
					out.print(objJson);
					
				}
				else if(uri.endsWith("add_history.do"))
				{	
					String val = req.getParameter("val");
					System.out.println("hit inside add_history");
					System.out.println(val);
					objJson = T1.insertTable("medical_history",val);
					out.print(objJson);
				}
				else if(uri.endsWith("add_allergy.do"))
				{	
					String val = req.getParameter("val");
					System.out.println(val);
					System.out.println("hit inside add_allergy");
					objJson = T1.insertTable("allergy_information",val);
					out.print(objJson);
					
				}
		}
		catch(Throwable e)
		{
			e.printStackTrace();
		}
		
	}

}
	
