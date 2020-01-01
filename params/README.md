## Configure the params of the project

In the file called ```params.csv``` you'll find this configuration to fill:

~~~
name_of_files
[name1.csv]:[name2.csv]
~~~

>Note that the files are separated by :

~~~
delimiters_of_files_data
,:;
~~~
>Each file will be separated by different internally delimiters. Write them in the order in which you declared 
>the names above

~~~
type_of_file 
0:1
~~~
>Here you choose if the file has a representation like that of Revolut or another. For now there are two implementations: 
>for Caja Rural (0) and for Revolut (1).