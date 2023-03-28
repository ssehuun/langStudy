#-*- coding: utf-8 -*-
import warnings
import shutil
import subprocess
import time
import selenium
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
warnings.filterwarnings('ignore')

options = Options()
options.binary_location= 'C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe'

driver = webdriver.Chrome(executable_path='C:\\Users\\user\\Downloads\\chromedriver_win32\\chromedriver.exe', chrome_options = options) ## 크롬 드라이버가 위치한 경로 대입 필요
driver.get('https://datalab.naver.com/shoppingInsight/sCategory.naver')

time.sleep(1)


driver.find_element(By.XPATH, '//*[@id="18_device_0"]').click() #기기별 클릭
#time.sleep(0.5)
driver.find_element(By.XPATH, '//*[@id="19_gender_0"]').click() #성별 클릭
#time.sleep(0.5)
driver.find_element(By.XPATH, '//*[@id="20_age_0"]').click() #연령별 클릭
#time.sleep(0.5)


driver.find_element(By.XPATH, '//*[@id="content"]/div[2]/div/div[1]/div/div/div[1]/div/div[1]/span').click() #분야 클릭
#time.sleep(0.5)

driver.find_element(By.XPATH, '//*[@id="content"]/div[2]/div/div[1]/div/div/div[1]/div/div[1]/ul/li[4]/a').click() #디지털/가전 클릭
#time.sleep(0.5)

driver.find_element(By.XPATH, '//*[@id="content"]/div[2]/div/div[1]/div/a').click() #조회하기 클릭
#time.sleep(1)

#def write_excel():
from openpyxl import Workbook
wb = Workbook()
ws = wb.create_sheet('keyword')
wb.remove_sheet(wb['Sheet'])
ws.append((['No', '인기검색어']))

for i in range(0, 25) :
    for j in range(1, 21) :
        path = f'//*[@id="content"]/div[2]/div/div[2]/div[2]/div/div/div[1]/ul/li[{j}]/a'
        result= driver.find_element(By.XPATH, path).text
        print(result.split('\n'))
        time.sleep(0.1)
        ws.append(result.split('\n'))
    driver.find_element(By.XPATH, '//*[@id="content"]/div[2]/div/div[2]/div[2]/div/div/div[2]/div/a[2]').click()
    time.sleep(0.1)

wb.save('C:\\Users\\user\\.virtualenvs\\naverdatalabtop500.xlsx')
wb.close()

driver.close()
driver.quit()

print("네이버 데이터랩 Top 500 키워드 뽑기 완료")
