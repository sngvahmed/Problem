package terminal;

import java.util.*;
import java.io.*;

public class data {
	public static void Date() {
		int day, month, year, second, min, hour;
		GregorianCalendar DT = new GregorianCalendar();

		day = DT.get(Calendar.DAY_OF_MONTH);
		month = DT.get(Calendar.MONTH);
		year = DT.get(Calendar.YEAR);

		second = DT.get(Calendar.SECOND);
		min = DT.get(Calendar.MINUTE);
		hour = DT.get(Calendar.HOUR);

		System.out.println("the data is ::  " + day + "/" + month + "/" + year);
		System.out.println("the time is ::  " + hour + "::" + min + "::"
				+ second);
	}
}
