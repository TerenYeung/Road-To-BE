from django.contrib import admin
from .models import Author, Genre, Book, BookInstance, Language

# Register your models here.
class BooksInline(admin.TabularInline):
  model = Book

class AuthorAdmin(admin.ModelAdmin):
  list_display = ('last_name', 'first_name', 'date_of_birth', 'date_of_death')
  fields = ['first_name', 'last_name', ('date_of_birth', 'date_of_death')]
  inlines = [BooksInline]

class BookInstantceInline(admin.TabularInline):
  model = BookInstance

@admin.register(Book)
class BookAdmin(admin.ModelAdmin):
  list_display = ('title', 'author', 'display_genre')
  inlines = [BookInstantceInline]

@admin.register(BookInstance)
class BookInstanceAdmin(admin.ModelAdmin):
  # list_display = ('id', 'book', 'imprint', 'due_back', 'status')
  list_filter = ('status', 'due_back')
  fieldsets = (
    (None, {
      'fields': ('book', 'imprint', 'id')
    }),
    ('Availability', {
      'fields': ('status', 'due_back')
    })
  )

# admin.site.register(Book)
admin.site.register(Author, AuthorAdmin)
admin.site.register(Genre)
# admin.site.register(BookInstance)
admin.site.register(Language)