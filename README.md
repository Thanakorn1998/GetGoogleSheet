# GetGoogleSheet
--------------
### GetGoogleSheet สามารถส่ง HTTP Request Method GET ไปยัง Google Apps Script โดยสามารถใช้กับ ESP32 สามารถส่งข้อมูลไปยัง คอลัมน์ A-Z ตามที่กำหนดได้
--------------
### ตัวอย่างการส่ง
วิธีใช้จะค่อนข้างง่าย
* เริ่มต้นให้กำหนด Instance GetGoogleSheet Fn1;
* กำหนด token ใช้ฟังชัน Fn1.begin(column,token);
* หากส่งข้อความใช่ฟังก์ชั้น Fn1.Get(column,get parameter,value);
* ขั้นตอนสุดท้ายในการส่งข้อมูลใช้ฟังก์ชัน Fn1.submit();