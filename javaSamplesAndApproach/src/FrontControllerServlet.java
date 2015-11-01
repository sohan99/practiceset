
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
import java.sql.PrepaedStatement;
import java.sql.ResultSet;
import java.sql.*;

import java.util.Map;
import org.json.simple.JSONObject;

public class FrontControllerServlet extends HttpServlet	
{
	HttpSession session = null;
	
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
		HttpSession session = req.getSession(false);
        PrintWriter out = res.getWriter();
		
		
		
		//strContextPath = session.getServletContext().getContextPath();
		String uri = req.getRequestURI();
		System.out.println("uri ================ "+uri);
		res.setContentType("text/html");
		System.out.println("session ================ "+session);

		try
		{
		    if(session == null)
			{
				
				
				// System.out.println("inside ================ "+uri);
				// 	RequestDispatcher dispatcher = req.getRequestDispatcher("TEST.html");
				// 	dispatcher.include(req,res);

                out.print("SESSION EXPIRED");
				
			}
			else{
				//session.setAttribute("DAYCARE", 10);
				
				if(uri.endsWith("login.eras") || uri.equals("/telerasETL/"))
				{
					RequestDispatcher dispatcher = req.getRequestDispatcher("ERASHomePage.html");
					dispatcher.include(req,res);
					java.util.Date date= new java.util.Date();
					System.out.println(new Timestamp(date.getTime()));
					session.setAttribute("loginTimeSession",new Timestamp(date.getTime()));
					
				}
			}	
		}
		catch(Throwable e)
		{
			e.printStackTrace();
			//rd = req.getRequestDispatcher("/Error.jsp");
			//rd.forward(req,res);
		}
		
	}

}
	
