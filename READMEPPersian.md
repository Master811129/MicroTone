## MicroTone: A high-performance library with super tiny flash usage to create a pulse train on the OCR0A pin on Attiny13
## Install
The library can be installed manually (by unzipping and copying the files to the "libraries" directory) or using the Arduino Library installer, there is nothing to care about.

## Supported Platforms
this library was designed ONLY for attiny13A/L MCU

## functions
این تابع کتابخانه را آماده سازی می کند
MicroTone.begin();

شما همچنین میتوانید از این تابع برای تنظیم بسامد کاری شمارنده ی داخلی میکروکنترلر استفاده کنید این عدد میتواند بین یک تا پنج باشد (default = 3)
MicroTone.begin(prescale);//1-5

This function creates a pulse train on the OCR0A pin note that the parameter (like any write() function) MUST be an 8-bit value (0-255) lower value gives highier frequency

MicroTone.write(value);

This function stops the pulse train (like noTone() function)

MicroTone.stop();

This function changes the prescaler anytime you want! the given value must be from 1 to 5

MicroTone.setPrescaler();
