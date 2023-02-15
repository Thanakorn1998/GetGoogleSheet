# GetGoogleSheet
--------------
### GetGoogleSheet สามารถส่ง HTTP Request Method GET ไปยัง Google Apps Script โดยสามารถใช้กับ ESP32 สามารถส่งข้อมูลไปยัง คอลัมน์ A-Z ตามที่กำหนดได้
--------------
### ตัวอย่างการส่ง
วิธีใช้จะค่อนข้างง่าย
* เริ่มต้นให้กำหนด Instance GetGoogleSheet Fn1; จำนวนคอลัมน์ที่ใช้ทั้งหนด
* กำหนด token ใช้ฟังชัน Fn1.begin(column,token);
* หากส่งข้อความใช่ฟังก์ชั้น Fn1.Get(column,get parameter,value);
* ขั้นตอนสุดท้ายในการส่งข้อมูลใช้ฟังก์ชัน Fn1.submit();
---------------
### ตัวอย่าง Google Apps Script

function doGet(e) {
  var sheet = SpreadsheetApp.getActiveSheet();
  var headers = sheet.getRange(1, 1, 1, 4).getValues()[0];
  
  if (headers[0] != "header1" || headers[1] != "header2" || headers[2] != "header3" || headers[3] != "header4") {
    sheet.insertRowBefore(1);
    sheet.getRange(1, 1, 1, 4).setValues([["header1", "header2", "header3", "header4"]]);
  }
  var value1 = e.parameter.value1;
  var value2 = e.parameter.value2;
  var value3 = e.parameter.value3;
  var value4 = e.parameter.value4;
  sheet.appendRow([value1, value2, value3, value4]);
  separateTextInColumnD();
}


function separateTextInColumnD() {
  var sheet = SpreadsheetApp.getActiveSheet();
  
  // Get the data from the Google Script
  // The specific implementation of this will depend on how the data is being sent to the Google Sheet
  
  // Add the data to the next empty row in the sheet
  var nextRow = sheet.getLastRow() + 1;
  sheet.getRange(nextRow, 4).setValue(data);
  
  // Replace all underscores with spaces in column D
  var columnDRange = sheet.getRange("D:D");
  var data = columnDRange.getValues();
  for (var i = 0; i < data.length; i++) {
    data[i][0] = data[i][0].replace(/_/g, " ");
  }
  columnDRange.setValues(data);
}
