set rtp+=/home/bq/.vim/bundle/Vundle.vim,home/bq/.vim/setting_gyoo.vim " defined vundle path

" initialize plugins

call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'nanotech/jellybeans.vim' " vim UI
Plugin 'scrooloose/nerdtree' " show file directory
Plugin 'vim-airline/vim-airline' " show underbar
Plugin 'airblade/vim-gitgutter' " Shows the difference from the previous log.
Plugin 'tpope/vim-fugitive' " view checkout pos of tree in git
Plugin 'scrooloose/syntastic' " syntax plugin
Plugin 'preservim/nerdcommenter'

call vundle#end()

Plugin 'setting_gyoo.vim'
filetype plugin on

let extension = expand('%:e')
if extension == ("js" || "css")
    nnoremap <F9> :!npm run start<CR>
elseif extension == "py"
    nnoremap <F9> :!python %<CR>
    nnoremap <S-F9> :!python -m pdb %<CR>
endif

" setting plugins

set backspace=2


set smartindent
set tabstop=4
set expandtab
set shiftwidth=4

nnoremap <C-j> :move +1<CR>
nnoremap <C-k> :move -2<CR>
nnoremap <F3> :NERDTreeToggle<CR>
