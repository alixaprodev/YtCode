package com.alixaprodev.usdataapi.utils;

import android.net.Uri;

import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Scanner;

public class NetworkUtils {
    final static String USADARA_BASE_URL="https://datausa.io/api/data?drilldowns=State&measures=Population&year=latest";

    public static URL buildUrl(){

        Uri urlStr = Uri.parse(USADARA_BASE_URL)
                .buildUpon().build();
        URL url= null;
        try {
            url = new URL(urlStr.toString());
        } catch (MalformedURLException e) {
            e.printStackTrace();
        }

        return url;
    }

    public static String getDatafromHttpUrl(URL url) throws IOException {
        HttpURLConnection connection = (HttpURLConnection)url.openConnection();
        try {
            InputStream stream = connection.getInputStream();
            Scanner scanner = new Scanner(stream);
            scanner.useDelimiter("\\A");
            boolean hasnext = scanner.hasNext();
            if (hasnext) {
                return scanner.next();
            } else
                return null;
        }
        finally {
            connection.disconnect();
        }

    }




}
