--- Задание 3. Создайте базу данных «Музыкальная коллекция».
--- База данных должна содержать информацию о музыкальных дисках, исполнителях, стилях. Необходимо хранить
--- следующую информацию:
---     1. О музыкальном диске: название диска, исполнитель, дата выпуска, стиль, издатель
---     2. О стилях: названия стилей
---     3. Об исполнителях: название
---     4. Об издателях: название, страна
---     5. О песнях: название песни, название диска, длительность песни, музыкальный стиль песни, исполнитель.

--- Продумайте правильную структуру базы данных. Для создания базы данных используйте запрос CREATE DATABASE.
--- Для создания таблицы используйте запрос CREATE TABLE.
--- Обязательно при создании таблиц задавать связи между ними.


use [master];
go

if db_id('Music_collection') is not null
begin
	drop database [Music_collection];
end
go

create database [Music_collection];
go

use [Music_collection];
go

---     1. О музыкальном диске: название диска, исполнитель, дата выпуска, стиль, издатель
create table [Disk]
(
	[Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N''),
	[AuthorId] int not null,
	[PublishDate] date not null ,
    [GenreId] int not null,
    [PublisherId] int not null
);
go

---     2. О стилях: названия стилей
create table [Genre]
(
    [Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

---     3. Об исполнителях: название
create table [Author]
(
    [Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N'')
);
go

---     4. Об издателях: название, страна
create table [Publisher]
(
    [Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N''),
	[Country] nvarchar(100) not null check ([Country] <> N'')
);
go

---     5. О песнях: название песни, название диска, длительность песни, музыкальный стиль песни, исполнитель.
create table [Song]
(
    [Id] int not null identity(1, 1) primary key,
	[Name] nvarchar(100) not null unique check ([Name] <> N''),
	[Durability] float not null check (Durability>0),
	[DiskId] int not null
);
go

alter table [Disk]
add foreign key ([AuthorId]) references [Author]([Id]);
go

alter table [Disk]
add foreign key ([GenreId]) references [Genre]([Id]);
go

alter table [Disk]
add foreign key ([PublisherId]) references [Publisher]([Id]);
go

alter table [Song]
add foreign key ([DiskId]) references [Disk]([Id]);
go

--- Song -> Disk -> Author|Genre|Publisher

insert into Publisher(Name,Country)
values
('Britain Records','Britain'),
('USA Records','USA'),
('Russian Records','Russia'),
('Indian Records','India'),
('China Records','China')
;

insert into Genre(Name)
values
('Indie Rock'),
('Doom Metal'),
('Core Metal'),
('D&B')
;

insert into Author(Name)
values
('Deathclock'),
('Rolling Stones'),
('Muse'),
('Pirate Station')
;

insert into Disk(Name,AuthorId,PublishDate,GenreId,PublisherId)
values
('Trash',4,'2010-03-2',4,2),
('Hard',1,'2000-07-2',2,1),
('Indastrial',3,'2012-03-2',1,3),
('Stones',2,'1989-03-2',1,4),
('About life',3,'2001-02-12',1,5),
('Some kind',4,'2010-03-2',4,2),
('Polka',4,'2012-12-22',4,3)
;

insert into Song(Name,Durability,DiskId)
values
('First',3.55,1),
('Second',3.25,2),
('Third',4.55,3),
('Uno',3.51,4),
('Ich',3.15,5),
('Nee',4.35,6),
('San',3.21,7),
('Chee',3.35,5),
('Go',4.15,6),
('Rok',3.15,4),
('Sich',4.35,3),
('Hach',3.21,2),
('Ku',3.35,1),
('Dzyu',4.15,1),
('Dzyu-Ich',3.21,2),
('Dzyu-Nee',3.35,1),
('Dzyu-San',4.15,1),
('Dzyu-Chee',3.21,2),
('Dzyu-Go',3.35,1),
('Dzyu-Rok',4.15,1)
;

--- Exercises ---

---	Задание 1. Все задания необходимо выполнить по отношению к базе данных «Музыкальная коллекция»,
---	описанной в практическом задании для этого модуля. Создайте следующие представления: 

---		1. Представление отображает названия всех исполнителей 
create view SingersView as
select Name from Author;

---		2. Представление отображает полную информацию о всех песнях: название песни, название диска, длительность песни, музыкальный стиль песни, исполнитель 
create view SongInfoView as 
select song.name as 'Song' ,disk.name as 'Disk',Song.Durability,Genre.Name as 'Genre ',Author.Name as 'Author'
from song join Disk on Song.DiskId=Disk.Id
join Author on Author.Id=Disk.AuthorId
join Genre on Genre.Id=Disk.GenreId;

---		3. Представление отображает информацию о музыкальных дисках конкретной группы. Например, The Beatles 
create view ParticularAuthorView as 
select Disk.Name as 'Disk',Author.Name as 'Author',PublishDate , Genre.Name as 'Genre',Publisher.Name as 'Publisher',Publisher.Country
from Disk join Author on Author.Id=Disk.AuthorId and Author.Name like 'Muse'
join Genre on Genre.Id=Disk.GenreId
join Publisher on Publisher.Id=Disk.PublisherId;

---		4. Представление отображает название самого популярного в коллекции исполнителя. Популярность определяется по количеству дисков в коллекции 
create view MostPopularView as 
select top 1 Author.Name , count(Disk.Id) as 'Disks'
from Disk join Author on Disk.AuthorId=Author.Id
group by Author.Name
order by 'Disks' desc;

---		5. Представление отображает топ-3 самых популярных в коллекции исполнителей. Популярность определяется по количеству дисков в коллекции 
create view Top3View as 
select top 3 Author.Name , count(Disk.Id) as 'Disks'
from Disk join Author on Disk.AuthorId=Author.Id
group by Author.Name
order by 'Disks' desc;

---		6. Представление отображает самый долгий по длительности музыкальный альбом
create view LongestDiskView as
select top 1 Disk.Name , sum(Song.Durability) as 'Time'
from song join Disk on Song.DiskId=Disk.Id
group by Disk.Name
order by 'Time' desc;
;

----- Updatable views

create view dbo.TestView (Name,Country) with schemabinding as
select Name,Country from dbo.Publisher;
go 
select * from TestView;
--- Без dbo. не работает . С schemabinding нельзя удалить таблицу , если на нее кто то ссылается









--- Сделать еще базу данных Продажи и остальные задания для этих баз.