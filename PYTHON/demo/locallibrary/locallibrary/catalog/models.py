from django.db import models
from django.urls import reverse # Used to generate URLs by reversing the URL patterns
import uuid # Require for unique book instances

# Create your models here.
class Genre(models.Model):
  '''
  Model representing a book genre(e.g. Sceience Fiction, No Fiction).
  '''

  name = models.CharField(max_length=200, help_text="Enter a book genre (e.g. Science Fiction)")

  def __str__(self):
    '''
    String for representing the Model object
    '''
    return self.name

class Book(models.Model):
  '''
  Model representing a book(but not a specific copy of a book).
  '''
  title = models.CharField(max_length=200)
  author = models.ForeignKey('Author', on_delete=models.SET_NULL, null=True)
  summary = models.TextField(max_length=1000, help_text='Enter a brief description of the book')
  isbn = models.CharField('ISBN', max_length=13, help_text='13 Character <a href="https://www.isbn-international.org/content/what-isbn">ISBN number</a>')
  genre = models.ManyToManyField(Genre, help_text='Select a genre for this book')
  language = models.ForeignKey('Language', on_delete=models.SET_NULL, null=True)

  def display_genre(self):
    return ', '.join([ genre.name for genre in self.genre.all()[:3]])
  display_genre.short_description = 'Genre'

  def __str__(self):
    return self.title
  
  def get_absolute_url(self):
    return reverse('book-detail', args=[str(self.id)])

class BookInstance(models.Model):
  '''
  Model representing a specific copy of a book.
  '''
  id = models.UUIDField(primary_key=True, default=uuid.uuid4, help_text='Unique ID for this particular book across whole library')
  book = models.ForeignKey(Book, on_delete=models.SET_NULL, null=True)
  imprint = models.CharField(max_length=200)
  due_back = models.DateField(null=True, blank=True)

  LOAN_STATUS = (
    ('m', 'Maintenance'),
    ('o', 'On loan'),
    ('a', 'Available'),
    ('r', 'Reserved'),
  )

  status = models.CharField(max_length=1, choices=LOAN_STATUS, blank=True, default='m', help_text='Book availability')

  class Meta:
      ordering = ['due_back']

  def __str__(self):
    return '{0} ({1})'.format(self.id, self.book.title)

class Author(models.Model):
  '''
  Model representing an autho.
  '''
  first_name = models.CharField(max_length=100)
  last_name = models.CharField(max_length=100)
  date_of_birth = models.DateField(null=True, blank=True)
  date_of_death = models.DateField('Died', null=True, blank=True)

  class Meta:
    ordering = ['last_name', 'first_name']

  def get_absolute_url(self):
    return reverse('author-detail', args=[str(self.id)])
  
  def __str__(self):
    return '{0}, {1}'.format(self.last_name, self.first_name)

class Language(models.Model):
  '''
  Model representing a Language (e.g. English, French, Japanese, etc.)
  '''
  name = models.CharField(max_length=200, help_text="Enter a the book's natural language")

  def __str__(self):
    return self.name