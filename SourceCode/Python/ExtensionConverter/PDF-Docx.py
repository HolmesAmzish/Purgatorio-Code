# File name:            PDF-DocxConverter.py
# Description:          Convert PDF to Docx file, pdf2docx should be installed before running.
# Install instroction:  pip install pdf2docx
# Date:                 2024.1.12
# Author:               Nulla

from pdf2docx import Converter

file = input("Please enter the pdf file name: ")

if '.pdf' in file:
    pdfFile = file
else:
    pdfFile = file + '.pdf'
# Detect whether the filename contains file extension

docxFile = pdfFile.replace('.pdf', '.docx')
cv = Converter(pdfFile)
cv.convert(docxFile)
cv.close()