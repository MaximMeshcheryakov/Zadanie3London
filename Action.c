Action()
{
	/* Itinerary */
	
	web_reg_save_param_ex(
    "ParamName=TicketCity", 
    "LB/IC= leaves ",
    "RB/IC=  for ",
    "Ordinal=all",
	LAST);
	
			
	web_reg_save_param_ex(
    "ParamName=FlightID", 
    "LB/IC=name=\"flightID\" value=\"",
    "RB/IC=\"  ",
    "Ordinal=all",
	LAST);
	
		
	web_reg_save_param_ex(
    	"ParamName=NumberOfTickets", 
    	"LB/IC=<b>A total of ", 	
    	"RB/IC= scheduled flight",								
    	"Ordinal=1",
	LAST);
	

	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("Total Number of tickets=%d",atoi(lr_eval_string("{NumberOfTickets}")));
	
	lr_output_message("Ticket City 1=%s",lr_eval_string("{TicketCity_1}"));
	lr_output_message("Ticket City 2=%s",lr_eval_string("{TicketCity_2}"));
	lr_output_message("Ticket City 3=%s",lr_eval_string("{TicketCity_3}"));
	
	
	if (strcmp (lr_eval_string("{TicketCity_1}"), str2)!=0){
      	lr_output_message("Del1");
      	lr_save_string("1", "num");
	}
	
	if (strcmp (lr_eval_string("{TicketCity_2}"), str2)!=0){
      	lr_output_message("Del2");
      	lr_save_string("2", "num");	
    }
	
	if (strcmp (lr_eval_string("{TicketCity_3}"), str2)!=0){
      	lr_output_message("Del3");
		lr_save_string("3", "num");
    }

	
	lr_output_message("DEL ticket=%d",atoi(lr_eval_string("{num}")));
	
	/* DEL TICKET */
	

	web_submit_data("itinerary.pl", 
		"Action={Host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/itinerary.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=flightID", "Value={FlightID_2}", ENDITEM, 
		"Name=flightID", "Value={FlightID_3}", ENDITEM, 
		"Name={num}", "Value=on", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=removeFlights.x", "Value=69", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);

	return 0;
}