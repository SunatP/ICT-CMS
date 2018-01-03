package snp.ict_cms;

import android.app.Dialog;
import android.app.ListActivity;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup.LayoutParams;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import org.apache.http.HttpResponse;

import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.w3c.dom.CharacterData;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import org.xml.sax.InputSource;
import org.xml.sax.SAXException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

/**
 * Created by Acer- on 2/12/2560.
 */

public class DataBase extends ListActivity {
    LinearLayout layout;

    public static final String url = "http://10.98.34.141/myweb/userlist.php";
    public static String result = "";
    List<User> users = new ArrayList<User>();

    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.user_db);

        WebPageTask task = new WebPageTask();
        task.execute();

    }

    @Override
    protected void onListItemClick(ListView l ,View v,int position, long id){
        User u = users.get(position);
        final Dialog dialog = new Dialog(DataBase.this);
        LinearLayout linearLayout = new LinearLayout(this);
        linearLayout.setPadding(10,10,10,10);
        TextView txt = new TextView(this);
        txt.setText("ID : " + u.username + "\nFirstname : " + u.firstname
        + "\nLastname : " + u.lastname +"\nEmail :" + u.email
        + "\nPhone : " + u.phone);
        linearLayout.addView(txt);
        dialog.setContentView(linearLayout, new LayoutParams(400,
                LinearLayout.LayoutParams.WRAP_CONTENT));
        dialog.setTitle("User Detail");
        dialog.setCancelable(true);
        dialog.show();
    }

    public void showAlluser(){
        ArrayAdapter<User> adapter = new ArrayAdapter<User>(this,android.R.layout.simple_list_item_1, users);
        setListAdapter(adapter);
    }

    public String getData(String url){
        HttpClient httpclient = new DefaultHttpClient();
        HttpPost httpost = new HttpPost(url);
        BufferedReader in = null;
        try {
            HttpResponse response = httpclient.execute(httpost);
            in = new BufferedReader(new InputStreamReader(response.getEntity().getContent()));
            StringBuffer sb = new StringBuffer("");
            String line = "";
            String NL = System.getProperty("line.separator");
            while ((line = in.readLine()) != null)
            {
            sb.append(line + NL);
        }
        in.close();
            String page = sb.toString();
            return page;
        } catch (ClientProtocolException e) {
            // TODO Auto-generated catch block
        } catch (IOException e) {
            // TODO Auto-generated catch block
        }
        return null;
    }

public void parseXML(String xmlRecords){
    DocumentBuilder db = null;
    try {
        db= DocumentBuilderFactory.newInstance().newDocumentBuilder();
    }catch (ParserConfigurationException e){
        // TODO Auto-generated catch block
        e.printStackTrace();
    }
    InputSource is = new InputSource();
    is.setCharacterStream(new StringReader(xmlRecords));

    Document doc =null;
    try {
        doc = db.parse(is);
    }catch (SAXException e) {
    // TODO Auto-generated catch block
        e.printStackTrace();
    }catch (IOException e){
        // TODO Auto-generated catch block
        e.printStackTrace();
    }
    NodeList nodes = doc.getElementsByTagName("user");

    for (int i = 0 ;i<nodes.getLength();i++)
    {
        Element element = (Element) nodes.item(i);

        NodeList username = element.getElementsByTagName("username");
        Element line = (Element) username.item(0);
        User u = new User();
        u.username = getCharacterDataFromElement(line);

        NodeList password = element.getElementsByTagName("password");
        line = (Element) username.item(0);
        u.username = getCharacterDataFromElement(line);

        NodeList firstname = element.getElementsByTagName("firstname");
         line = (Element) firstname.item(0);
        u.firstname = getCharacterDataFromElement(line);

        NodeList lastname = element.getElementsByTagName("lastname");
         line = (Element) lastname.item(0);
        u.lastname = getCharacterDataFromElement(line);

        NodeList email = element.getElementsByTagName("email");
         line = (Element) email.item(0);
        u.email = getCharacterDataFromElement(line);

        NodeList phone = element.getElementsByTagName("phone");
         line = (Element) phone.item(0);
         u.phone = getCharacterDataFromElement(line);
         NodeList register_date = element
                 .getElementsByTagName("register_date");
        line = (Element) register_date.item(0);
        u.register_date = getCharacterDataFromElement(line);

        users.add(u);
    }
}

public String getCharacterDataFromElement(Element e){
    Node child = e.getFirstChild();
    if (child instanceof CharacterData)
    {
        CharacterData cd = (CharacterData) child;
        return cd.getData();
    }
    return "";
}

    class User{
        public String username;
        public String password;
        public String firstname;
        public String lastname;
        public String email;
        public String phone;
        public String register_date;

        @Override
        public String toString(){
            return username;
        }
    }

    private class WebPageTask extends AsyncTask<Void, Void, String> {
    // TO ECHO system
        @Override
        protected String doInBackground(Void... param) {

            String xml_text = getData(url);
            parseXML(xml_text);
            return null;
        }

        @Override
        protected void onPostExecute(String result){

            Toast.makeText(DataBase.this, "Load Data Complete",Toast.LENGTH_LONG).show();
            showAlluser();
        }
    }
}
