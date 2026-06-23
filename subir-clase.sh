#!/bin/bash

# Verificar que estemos dentro de un repositorio Git
if ! git rev-parse --is-inside-work-tree > /dev/null 2>&1; then
    echo "Error: esta carpeta no es un repositorio Git."
    exit 1
fi

# Crear mensaje con fecha en formato dd/mm/aaaa
FECHA=$(date +"%d/%m/%Y")
MENSAJE="Clase $FECHA"

echo "Agregando cambios..."
git add .

# Verificar si hay cambios para commitear
if git diff --cached --quiet; then
    echo "No hay cambios para guardar."
    exit 0
fi

echo "Creando commit: $MENSAJE"
git commit -m "$MENSAJE"

echo "Subiendo cambios a GitHub..."
git push

echo "Listo. Commit enviado con mensaje: $MENSAJE"